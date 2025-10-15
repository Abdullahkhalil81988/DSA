#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>
#include <iostream>

struct Point {
    int row;
    int col;
    Point(int r = -1, int c = -1) : row(r), col(c) {}
};

class Maze {
private:
    std::vector<std::vector<char>> grid;
    Point start;
    Point goal;

public:
    bool loadFromFile(const std::string &filename);
    void printMaze() const;

    int getHeight() const;
    int getWidth() const;
    char getCell(int r, int c) const;
    void setCell(int r, int c, char value);
    Point getStart() const;
    Point getGoal() const;
};

#endif
