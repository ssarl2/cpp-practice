// https://adventofcode.com/2018/day/7

#include <iostream>
#include <vector>
#include <tools.h>

class Node
{
public:
    Node(char node)
    {
        node_ = node;
    }
    bool hasNext()
    {
        if(!next_nodes_.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void setNextNode(std::vector<Node> next_nodes)
    {
        // would this be shallow copy or deep copy?
        next_nodes_ = next_nodes;
    }
private:
    char node_;
    std::vector<Node> next_nodes_;
};

class NodeTree
{
public:
    NodeTree(std::vector<Node> nodes)
    {
        nodes_ = nodes;
        connectNodes();
    }
    void solve()
    {

    }
private:
    void connectNodes()
    {

    }
    std::vector<Node> nodes_;
};

int main(int argc, char *argv[])
{
    return 0;
}
/*
* 1. Make a node or a tree with given input
*    First, find first and last alphabets.
*    second, attach nodes(alphabets) from the first node(alphabet).
* 2. Arrange the order with below tips
*    Current order has all available next alphabets.
*    Alphavets can be compared as askii code.
*/