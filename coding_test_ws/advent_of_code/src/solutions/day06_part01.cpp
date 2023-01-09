// https://adventofcode.com/2018/day/6

#include <iostream>
#include <sstream>
#include <fstream>
#include <tools.h>
#include <set>

tools::debug_level debug_mode = tools::normal;

struct Boundary
{
    int lowest_x;
    int lowest_y;
    int highest_x;
    int highest_y;
};

struct Point
{
    int location_name;
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
    Point(int x, int y, int name) : x(x), y(y), location_name(name) {}
};

class Solution
{
public:
    Solution(std::vector<std::string> lines)
    {
        int i = 0;
        for(const auto& line : lines)
        {
            std::vector<std::string> tokens = tools::tokenizing(line, ", ");
            Point p{std::stoi(tokens.at(0)), std::stoi(tokens.at(1)), i++};
            location_points_.push_back(p);
        }
    }

    void setBoundaries()
    {
        std::vector<int> v_x;
        std::vector<int> v_y;
        for(const auto& lp : location_points_)
        {
            v_x.push_back(lp.x);
            v_y.push_back(lp.y);
        }
        boundary_box_.lowest_x = *std::min_element(v_x.begin(), v_x.end());
        boundary_box_.lowest_y = *std::min_element(v_y.begin(), v_y.end());
        boundary_box_.highest_x = *std::max_element(v_x.begin(), v_x.end());
        boundary_box_.highest_y = *std::max_element(v_y.begin(), v_y.end());
    }

    void setCoordinates(int boundary)
    {
        for (size_t x = 0; x < boundary; x++)
        {
            for (size_t y = 0; y < boundary; y++)
            {
                Point cp{x,y};
                coordinate_points_.push_back(cp);
            }
        }
    }

    bool isInfiniteInCP(int location_name)
    {
        for(const auto &cp : coordinate_points_)
        {
            if(cp.location_name == location_name)
            {
                if(cp.x == boundary_box_.lowest_x ||
                cp.x == boundary_box_.highest_x ||
                cp.y == boundary_box_.lowest_y ||
                cp.y == boundary_box_.highest_y)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void changeLocation(int target_location)
    {
        for(auto &cp : coordinate_points_)
        {
            if(cp.location_name == target_location)
            {
                cp.location_name = -1;
            }
        }
    }

    int countValues(int value)
    {
        std::vector<int> v;
        for(const auto &cp : coordinate_points_)
        {
            v.push_back(cp.location_name);
        }
        return std::count(v.begin(), v.end(), value);
    }

    void run()
    {
        for(auto& c_p : coordinate_points_)
        {
            /* key : index of location
             * value : distance to the location from the current coordinate
             */
            std::map<int, int> distances;


            for(const auto& l_p : location_points_)
            {
                int distance = std::abs(c_p.x - l_p.x) + std::abs(c_p.y - l_p.y);
                distances.insert({l_p.location_name, distance});
            }

            auto shortest_d = tools::minMapElement(distances);

            if(tools::countValues(distances, shortest_d->second) > 1)
            {
                c_p.location_name = 0;
            }
            else
            {
                c_p.location_name = shortest_d->first;
            }

        }

        for(const auto& l_p : location_points_)
        {
            if(isInfiniteInCP(l_p.location_name))
            {
                changeLocation(l_p.location_name);
            }
        }

        printInFile(coordinate_points_, 400);

        int largest_area = 0;
        int index = 0;
        for(auto l_p : location_points_)
        {
            if(countValues(l_p.location_name) > largest_area)
            {
                largest_area = countValues(l_p.location_name);
                index = l_p.location_name;
            }
        }

        tools::log(debug_mode, "largest area : " + std::to_string(largest_area));
        tools::log(debug_mode, "location number : " + std::to_string(index));
    }

    void printInFile(std::vector<Point> points, int printing_size)
    {
        std::map<std::pair<int,int>,int> map;
        for(auto p : points)
        {
            map.insert({{p.x,p.y},p.location_name});
        }

        std::ofstream file;
        file.open("drawing_day06_part01.txt");
        for (size_t i = 0; i < printing_size; i++)
        {
            for (size_t j = 0; j < printing_size; j++)
            {
                std::pair<int,int> coordinate{i,j};
                if(map.find(coordinate)->second == 0)
                {
                    file << ".  ";
                }
                else if(map.find(coordinate)->second == -1)
                {
                    file << "-1 ";
                }
                else
                {
                    if(map.find(coordinate)->second < 10)
                    {
                        file << "0" << map[coordinate] << " ";
                    }
                    else
                    {
                        file << map[coordinate] << " ";
                    }
                }
            }
            file << std::endl;
        }

        file.close();
    }
private:
    Boundary boundary_box_;
    std::vector<int> boundary_locations_;
    std::vector<Point> location_points_;
    std::vector<Point> coordinate_points_;
    // std::map<int,std::pair<int,int>> locations_; // name of location, coordinate of location
    int longest_distance_x_;
    int longest_distance_y_;
    std::map<std::pair<int,int>,int> distance_map_; // coordinate of location, closest index to a location
};

int main(int argc, char *argv[])
{
    // std::vector<std::string> vec_str = tools::readFileAsVecStr(argv[1]);
    std::vector<std::string> vec_str = tools::readFileAsVecStr("../input/day06_input01.txt");

    Solution s(vec_str);

    s.setBoundaries();
    s.setCoordinates(500);
    s.run();

    tools::log(debug_mode, "Drew day06_part01");
    return 0;
}
/*
* if closest distance is more than x, it's infinite
** a largest integer of coordinates' sums
* Algorithm of Manhattan distance
** |x1-x2| + |y1-y2|
* Solution
** Compare each coordinates' closest locations under maximum distance
*/