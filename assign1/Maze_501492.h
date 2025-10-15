#ifndef MAZE_H
#define MAZE_H

// needed libraries
#include <vector>
#include <string>
#include <iostream>
using namespace std;


// stores row and column positions
struct Point
{
    int row;    
    int col;    
    Point(int r = -1, int c = -1) : row(r), col(c) {} 
};

// class for maze operations
class Maze
{
private:
    vector<vector<char>> grid;   
    Point start;                  
    Point goal;                   

public:
    // load maze from file
    bool loadFromFile(const string &filename);
    // display maze
    void printMaze() const;

    // get maze height
    int getHeight() const { return grid.size(); }
    // get maze width
    int getWidth() const { return grid.empty() ? 0 : grid[0].size(); }

    // get cell value at position
    char getCell(int r, int c) const {
        if (r < 0 || r >= getHeight() || c < 0 || c >= getWidth()) {
            throw std::out_of_range("Cell indices out of bounds");
        }
        return grid[r][c];
    }
    // set cell value at position
    void setCell(int r, int c, char value) {
        if (r < 0 || r >= getHeight() || c < 0 || c >= getWidth()) {
            throw std::out_of_range("Cell indices out of bounds");
        }
        grid[r][c] = value;
    }

    // get start position
    Point getStart() const { return start; }
   
    // get goal position
    Point getGoal() const { return goal; }
};

#endif
