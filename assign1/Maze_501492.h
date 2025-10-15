#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Point
{
    int row;
    int col;
    Point(int r = -1, int c = -1) : row(r), col(c) {}
};

class Maze
{
private:
    vector<vector<char>> grid;
    Point start;
    Point goal;

public:
    bool loadFromFile(const string &filename);
    void printMaze() const;

    int getHeight() const { return grid.size(); }
    int getWidth() const { return grid.empty() ? 0 : grid[0].size(); }

    char getCell(int r, int c) const {
        if (r < 0 || r >= getHeight() || c < 0 || c >= getWidth()) {
            throw std::out_of_range("Cell indices out of bounds");
        }
        return grid[r][c];
    }
    void setCell(int r, int c, char value) {
        if (r < 0 || r >= getHeight() || c < 0 || c >= getWidth()) {
            throw std::out_of_range("Cell indices out of bounds");
        }
        grid[r][c] = value;
    }

    Point getStart() const { return start; }
    Point getGoal() const { return goal; }
};

#endif
