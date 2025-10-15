#ifndef SOLVER_H
#define SOLVER_H

#include "Maze_501492.h"
#include <stack>
#include <vector>
#include <string>

class Solver {
private:
    std::vector<std::vector<bool>> visited;
    std::vector<std::vector<Point>> parent;

    bool isValidMove(const Maze& maze, int r, int c);
    void reconstructPath(Maze& maze, const Point& start, const Point& goal);

public:
    bool solve(Maze& maze);
    void writeParentArrayToCSV(const std::string& filename);
};

#endif
