#ifndef SOLVER_H
#define SOLVER_H

// needed libraries
#include "Maze_501492.h"
#include <stack>
#include <vector>
using namespace std;

// finds path in maze
class Solver {
private:
    // position in maze
    struct Node {
        int row, col;
    };

    // tracks visited cells
    vector<vector<bool>> visited;
    // tracks path to each cell
    vector<vector<Point>> parent;

    // checks valid moves
    bool isValidMove(const Maze& maze, int r, int c);
    // creates solution path
    void reconstructPath(Maze& maze, const Point& start, const Point& goal);

public:
    // solves the maze
    bool solve(Maze& maze);
    // saves path data
    void writeParentArrayToCSV(const string& filename);
};

#endif
