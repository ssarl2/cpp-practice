// https://adventofcode.com/2018/day/6

#include <iostream>
#include <sstream>
#include <fstream>
#include <tools.h>

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

    void setCoordinatePoints(std::vector<Point>& coordinate_points, int boundary)
    {
        for (size_t x = 0; x < boundary; x++)
        {
            for (size_t y = 0; y < boundary; y++)
            {
                Point cp{x,y};
                coordinate_points.push_back(cp);
            }
        }
    }

    // a solution for part01
    void setShortestDistancesInCoordinatePoints(std::vector<Point>& coordinate_points)
    {
        for(auto& cp : coordinate_points)
        {
            /* key : index of location
             * value : distance to the location from the current coordinate
             */
            std::map<int, int> distances_to_target_locations;


            for(const auto& lp : location_points_)
            {
                int distance_to_target_location = std::abs(cp.x - lp.x) + std::abs(cp.y - lp.y);
                distances_to_target_locations.insert({lp.location_name, distance_to_target_location});
            }

            auto shortest_d = tools::minMapElement(distances_to_target_locations);

            if(tools::countTargetIntegerValuesInMap(distances_to_target_locations, shortest_d->second) == 1)
            {
                // if there's only one that's the shortest distance to the target location from the coordinate
                cp.location_name = shortest_d->first;
            }
            else
            {
                // there's no only one shortest distance or more than 1
                cp.location_name = 0;
            }
        }
    }

    void deleteInfiniteAreaInCoordinatePoints(std::vector<Point>& coordinate_points)
    {
        for(const auto& lp : location_points_)
        {
            if(isInfiniteInCoordinatePoints(coordinate_points, lp.location_name))
            {
                deleteClosestPointInCoordinatePoints(coordinate_points, lp.location_name);
            }
        }
    }

    bool isInfiniteInCoordinatePoints(std::vector<Point>& coordinate_points, int location_name)
    {
        for(const auto& cp : coordinate_points)
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

    void deleteClosestPointInCoordinatePoints(std::vector<Point>& coordinate_points, int target_location)
    {
        for(auto& cp : coordinate_points)
        {
            if(cp.location_name == target_location)
            {
                cp.location_name = -1;
            }
        }
    }

    int countAreaOfTargetLocationNameInCoordinatePoints(std::vector<Point>& coordinate_points, int value)
    {
        std::vector<int> v;
        for(const auto& cp : coordinate_points)
        {
            v.push_back(cp.location_name);
        }
        return std::count(v.begin(), v.end(), value);
    }

    void solvePart01()
    {
        setCoordinatePoints(coordinate_points_part01_, 500);
        setShortestDistancesInCoordinatePoints(coordinate_points_part01_);
        deleteInfiniteAreaInCoordinatePoints(coordinate_points_part01_);
        printInFile(coordinate_points_part01_, 400);

        int largest_area = 0;
        int index = 0;
        for(auto lp : location_points_)
        {
            if(countAreaOfTargetLocationNameInCoordinatePoints(coordinate_points_part01_, lp.location_name) > largest_area)
            {
                largest_area = countAreaOfTargetLocationNameInCoordinatePoints(coordinate_points_part01_, lp.location_name);
                index = lp.location_name;
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
    std::vector<Point> location_points_; // array of target coordinates(x, y) and its name as an integer(location_name)
    std::vector<Point> coordinate_points_part01_; // array of a point of coordinates(x, y) and a closest target location(location_name)
};

int main(int argc, char *argv[])
{
    std::vector<std::string> vec_str = tools::readFileAsVecStr(argv[1]);

    Solution s(vec_str);

    s.setBoundaries();
    s.solvePart01();

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