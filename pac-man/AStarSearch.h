#pragma once
#include "Board.h"
struct Node
{
    int y;
    int x;
    int parentX;
    int parentY;
    float gCost;
    float hCost;
    float fCost;
};

inline bool operator < (const Node& lhs, const Node& rhs)
{//We need to overload "<" to put our struct into a set
    return lhs.fCost < rhs.fCost;
}

static bool isValid(int r, int c) { //check to make sure the row/col pair is a valid spot to move
    if ((r > 30 || c > 27) || (r < 0 || c < 0))
        return false;

}