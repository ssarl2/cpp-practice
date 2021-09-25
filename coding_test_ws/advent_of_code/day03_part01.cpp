// https://adventofcode.com/2018/day/3

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

class Claim
{
public:
    Claim(std::string claim);
    int getWidthClaim();
    int getHeightClaim();
    int getXFromLeft();
    int getYFromBottom();
private:
    std::vector<std::vector<int>> parseClaim(std::string claim, std::vector<char> delimiters);

    int claim_number_;
    int x_from_left_;
    int y_from_bottom_;
    int width_claim_;
    int height_claim_;
};

Claim::Claim(std::string claim)
{
    std::vector<char> delimiters{'@', ',', ':', 'x', '\0'};
    std::vector<std::vector<int>> parsed = Claim::parseClaim(claim, delimiters);
    for(const auto& token : parsed)
    {
        claim_number_ = token[0];
        x_from_left_ = token[1];
        y_from_bottom_ = token[2];
        width_claim_ = token[3];
        height_claim_ = token[4];
    }
}

int Claim::getWidthClaim()
{
    return width_claim_;
}

int Claim::getHeightClaim()
{
    return height_claim_;
}

int Claim::getXFromLeft()
{
    return x_from_left_;
}

int Claim::getYFromBottom()
{
    return y_from_bottom_;
}

std::vector<std::vector<int>> Claim::parseClaim(std::string claim, std::vector<char> delimiters)
{
    std::vector<std::vector<int>> parsed;
    std::vector<int> store_token;

    //* start after '#'
    std::size_t pos_start = 1;

    std::size_t pos_end = 0;
    std::size_t delim_len = 1;
    std::string token = "";

    //* remove whitespace
    claim.erase(std::remove(claim.begin(), claim.end(), ' '), claim.end());

    for (std::size_t i = 0; i < delimiters.size(); i++)
    {
        if(i!=delimiters.size()-1)
        {
            pos_end = claim.find(delimiters[i], pos_start);
        }
        else
        {
            pos_end = claim.size();
        }
        token = claim.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;

        store_token.push_back(std::stoi(token));
    }
    parsed.push_back(store_token);

    return parsed;
}

class Fabric
{
public:
    Fabric(std::vector<Claim>& claims);
    int getOverlappedClaim();
    void printFabric();
private:
    std::pair<int, int> calcFabricSize(std::vector<Claim>& claims);
    int checkOverlappedClaim(std::vector<Claim>& claims);

    std::map<std::pair<int,int>,int> fabric_claim_;
    int fabric_width_;
    int fabric_height_;
    int count_overlapped_claim_;
};

Fabric::Fabric(std::vector<Claim>& claims)
{
    std::tie(fabric_width_, fabric_height_) = calcFabricSize(claims);
    count_overlapped_claim_ = checkOverlappedClaim(claims);
}

int Fabric::getOverlappedClaim()
{
    return count_overlapped_claim_;
}

std::pair<int, int> Fabric::calcFabricSize(std::vector<Claim>& claims)
{
    int longest_x=0;
    int longest_y=0;

    for(auto& claim : claims)
    {
        if(claim.getXFromLeft() + claim.getWidthClaim() > longest_x)
        {
            longest_x = claim.getXFromLeft() + claim.getWidthClaim();
        }

        if(claim.getYFromBottom() + claim.getHeightClaim() > longest_y)
        {
            longest_y = claim.getYFromBottom() + claim.getHeightClaim();
        }
    }

    return std::make_pair(longest_x, longest_y);
}

int Fabric::checkOverlappedClaim(std::vector<Claim>& claims)
{
    int count_overlapped_claim = 0;
    int x = 0;
    int y = 0;

    for(auto& claim : claims)
    {
        for (std::size_t i = 0; i < claim.getHeightClaim(); i++)
        {
            for (std::size_t j = 0; j < claim.getWidthClaim(); j++)
            {
                x = claim.getXFromLeft() + j;
                y = claim.getYFromBottom() + i;
                
                //* increase a value a pair key if finds the pair key(overlapped claim)
                auto it = fabric_claim_.find(std::make_pair(x, y));
                if(it != fabric_claim_.end())
                {
                    it->second++;
                    continue;
                }
                
                fabric_claim_.insert(std::make_pair(std::make_pair(x, y), 1));
            }
        }
    }

    for(const auto& f_claim : fabric_claim_)
    {
        if(f_claim.second > 1)
        {
            count_overlapped_claim++;
        }
    }

    return count_overlapped_claim;
}

void Fabric::printFabric()
{
    for (std::size_t i = 0; i < fabric_height_; i++)
    {
        for (std::size_t j = 0; j < fabric_width_; j++)
        {
            auto it = fabric_claim_.find(std::make_pair(j, i));
            if(it != fabric_claim_.end())
            {
                if(it->second>1)
                {
                    std::cout << "@";
                    continue;
                }
                std::cout << "*";
            }
            else
            {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::string line;
    std::ifstream* contents = new std::ifstream("../input/day03_input01.txt");
    std::vector<Claim> claims;

    //* parse lines
    while(std::getline(*contents, line))
    {
        Claim claim{line};
        claims.push_back(claim);
    }

    Fabric fabric{claims};
    fabric.printFabric();
    std::cout << "overlapped claims : " << fabric.getOverlappedClaim() << std::endl;

    //* create n claim objects
    //  * details of the object
    //  * a variable of x for the starting point
    //  * a variable of y for the starting point
    //  * a variable of the fabric width
    //  * a variable of the fabric height
    //  * a function of printing a fabric (when it prints, reverse y value)
    //* compare all each objects
    //  * a variable of total width of a fabric
    //  * a variable of total height of a fabric
    //  * a variable for counting overlapped claims
    //  * a function of comparing two claims whether they overlap
    //  * calculate overlapped claims and save it for the result
    //  * print a fabric with claims for fun

    return 0;
}
