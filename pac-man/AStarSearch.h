#pragma once
#include "Board.h"
#include <vector>
#include <queue>
#include <set>  //maybe use unordered instead
#include <iostream>


struct Node
{
    Node(int r, int c) { row = r; col = c; gCost = 0; hCost = 0; fCost = 0; parent = nullptr; }
    int row;
    int col;
    int gCost;  //cost so far
    int hCost;  // heuristic/ expected cost
    int fCost;  //total cost
    Node* parent;

    bool operator < (const Node& other) const
    {//inverted the < bcuz we want to adapt the priority queue's max heap to be like a min-heap
        return fCost > other.fCost;
    }
};

struct NodeManager
{
    NodeManager() {}
    ~NodeManager() {
        for (auto node : trash) {
            if (node != nullptr)
                delete node;
        }
    }
    std::vector<Node*> trash;
};

static void PrintPath(const std::vector<Node>& path)
{
    for (const Node& node : path)
    {
        std::cout << "(" << node.row << ", " << node.col << ") ";
    }
    std::cout << std::endl;
}

static std::vector<Node> findPath(Board* board, Node start, Node goal, NodeManager* manager)
{
    std::priority_queue<Node> openSet; //which nodes to expand
    std::set<std::pair<int, int>> visited;  //visited tiles

    //initialize the starting node
    start.gCost = 0;
    start.hCost = std::abs(goal.row - start.row) + std::abs(goal.col - start.col); // Manhattan distance
    start.fCost = start.gCost + start.hCost;
    openSet.push(start);

    //start of A*
    while (!openSet.empty())
    {
        Node current = openSet.top(); //should have the smallest f value due to the operator overload function
        openSet.pop();

        if (current.row == goal.row && current.col == goal.col) { //reconstruct path if reached goal
            std::vector<Node> path;
            Node* pathNode = &current;
            while (pathNode->parent !=nullptr) {
                path.push_back(*pathNode);
                pathNode = pathNode->parent;
            }
            std::reverse(path.begin(), path.end());
            PrintPath(path);
            return path;
        }


        visited.insert({ current.row, current.col });
        //and now explore it's neighbors
        std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        for (const auto& dir : directions) {
            int newRow = current.row + dir.first;
            int newCol = current.col + dir.second;

            //skip out of bounds
            if (newRow <0 || newRow> board->height - 1 || newCol <0 || newCol > board->width - 1)
                continue;

            if (visited.count({ newRow, newCol }))  //skip already visited nodes
                continue;

            // calculate costs for the neighbor
            Node neighbor(newRow, newCol);
            neighbor.gCost = current.gCost + 1; // cost from start to this neighbor
            neighbor.hCost = std::abs(goal.row - newRow) + std::abs(goal.col - newCol);
            neighbor.fCost = neighbor.gCost + neighbor.hCost;
            neighbor.parent = new Node(current); // Store parent to reconstruct path later
            manager->trash.push_back(neighbor.parent);

            // Add the neighbor to the open set
            openSet.push(neighbor);
        }
    }
    // If no path found, return empty
    return {};

}

