// https://adventofcode.com/2018/day/4

/* key point values
 * id : map - key
 * asleep_total : map - value(array), append
 * asleep_most : index value - asleep_total
 * words : wakes up, falls asleep, Guard #? begins shift
 */

/* functions
 * result : multiply id by the most minutes asleep
 * process1 : pick the most minutes id
 * process2 : make a structure or a class
 * process3 : count asleep minutes
 * process4 : store the count in the asleep_total array and the id
 * process5 : organize the order of the date as ascent
 * process? : ??
 */

// test

#include <iostream>
#include <fstream>
#include <ctime>
#include <tools.h>

tools::debug_level debug_mode = tools::normal;

class Parsing
{
public:
    Parsing(std::string line)
    : line_(line)
    , str_date_("")
    {}
    ~Parsing()
    {
        line_ = "";
        str_date_ = "";
    }
    void findAndCut(char c)
    {
        std::size_t found;
        found = line_.find(c);
        if (found != std::string::npos)
        {
            std::string cut = line_.substr(0, found);
            line_.erase(0, found + 1);
            str_date_.append(cut);
        }
        else
        {
            tools::log(debug_mode, "Couldn't find the character");
        }
    }
    void eraseLine(std::size_t pos, std::size_t n)
    {
        line_.erase(pos,n);
    }
    std::string getLine()
    {
        return line_;
    }
    std::string getStrDate()
    {
        return str_date_;
    }
private:
    std::string line_;
    std::string str_date_;
};

class Guards
{
public:
    Guards(){}
    void setState(std::vector<std::string> state)
    {
        int guard_number = 0;
        int time_asleep = 0;
        int time_awake = 0;

        for(auto line : state)
        {
            size_t found_guard_number = line.find('#');
            if (found_guard_number != std::string::npos)
            {
                size_t find_end_num = line.find("begins");
                guard_number = std::stoi(line.substr(found_guard_number + 1, find_end_num - found_guard_number - 2));
            }

            size_t found_asleep_time = line.find("falls");
            if (found_asleep_time != std::string::npos)
            {
                time_asleep = std::stoi(line.substr(found_asleep_time - 2, found_asleep_time));
            }

            size_t found_wakes_time = line.find("wakes");
            if (found_wakes_time != std::string::npos)
            {
                time_awake = std::stoi(line.substr(found_wakes_time - 2, found_wakes_time));

                setGuards(guard_number, time_asleep, time_awake);
            }
        }
    }

    std::map<int, std::map<int, int>> getGuards()
    {
        return guards_;
    }

    int getTotalAsleepMinutes(int guard_number)
    {
        int total_asleep_minutes = 0;
        if(guards_.find(guard_number) != guards_.end())
        {
            for(auto guard : guards_.at(guard_number))
            {
                total_asleep_minutes += guard.second;
            }
        }
        return total_asleep_minutes;
    }
private:
    void setGuards(int guard_number, int time_asleep, int time_awake)
    {
        for (size_t i = time_asleep; i < time_awake; i++)
        {
            if (guards_.find(guard_number) == guards_.end())
            {
                guards_.insert({guard_number, {}});
            }
            else
            {
                if (guards_.at(guard_number).find(i) == guards_.at(guard_number).end())
                {
                    guards_.at(guard_number).insert({i, 1});
                }
                else
                {
                    guards_.at(guard_number).at(i) += 1;
                }
            }
        }
    }
    /*
    * first key : guard number
    * second key : minutes that the guard was asleep
    * second value : counts that the guard was asleep
    */
    std::map<int, std::map<int, int>> guards_;
};

int main(int argc, char *argv[])
{
    std::string line;
    // std::string str_date;
    std::map<std::string, std::string> time_describe;
    std::ifstream infile(argv[1]);

    while (std::getline(infile, line))
    {
        Parsing p(line);
        p.findAndCut('[');
        p.findAndCut('-');
        p.findAndCut('-');
        p.findAndCut(' ');
        p.findAndCut(':');
        p.findAndCut(']');
        p.eraseLine(0, 1);
        time_describe.insert(std::pair<std::string, std::string>(p.getStrDate(), p.getLine()));
    }

    tools::sort(time_describe);

    Guards guards;
    std::vector<std::string> cache_lines;
    for (auto &m : time_describe)
    {
        size_t found_end = m.second.find("begins");
        if(found_end != std::string::npos)
        {
            guards.setState(cache_lines);
            cache_lines.clear();
        }
        cache_lines.push_back(m.first + m.second);
    }

    auto guards_info = guards.getGuards();

    int total_asleep_minutes = 0;
    int most_slept_guard_number = 0;
    for (auto &m : guards_info)
    {
        if(guards.getTotalAsleepMinutes(m.first) > total_asleep_minutes)
        {
            total_asleep_minutes = guards.getTotalAsleepMinutes(m.first);
            most_slept_guard_number = m.first;
        }
    }

    // find
    int most_slept_minutes = 0;
    auto me = std::max_element
    (
        guards_info.at(most_slept_guard_number).begin(), guards_info.at(most_slept_guard_number).end(),
        [] (const std::pair<int, int>& a, const std::pair<int, int>& b)->bool{ return a.second < b.second; }
    );

    most_slept_minutes = me->first;

    // find most frequently asleep things
    int most_frequently_asleep_times = 0;
    int most_frequently_asleep_minutes = 0;
    int most_frequently_asleep_guard_number = 0;
    for (auto &gi : guards_info)
    {
        auto me2 = std::max_element
        (
            guards_info.at(gi.first).begin(), guards_info.at(gi.first).end(),
            [] (const std::pair<int, int>& a, const std::pair<int, int>& b)->bool{ return a.second < b.second; }
        );

        if(most_frequently_asleep_times < me2->second)
        {
            most_frequently_asleep_times = me2->second;
            most_frequently_asleep_minutes = me2->first;
            most_frequently_asleep_guard_number = gi.first;
        }
    }

    tools::log(debug_mode, "Part 1.");
    tools::log(debug_mode, "Guard : " + std::to_string(most_slept_guard_number));
    tools::log(debug_mode, "At minutes : " + std::to_string(most_slept_minutes));

    tools::log(debug_mode, "Part 2.");
    tools::log(debug_mode, "Guard : " + std::to_string(most_frequently_asleep_guard_number));
    tools::log(debug_mode, "At minutes : " + std::to_string(most_frequently_asleep_minutes));
}