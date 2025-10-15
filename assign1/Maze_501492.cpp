#include "Maze_501492.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool Maze::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open maze file.\n";
        return false;
    }

    std::string line;
    grid.clear();
    int row = 0;

    while (std::getline(file, line)) {
        std::vector<char> rowData;
        std::stringstream ss(line);
        std::string cell;
        int col = 0;

        while (std::getline(ss, cell, ',')) {
            char ch = cell.empty() ? ' ' : cell[0];
            rowData.push_back(ch);
            if (ch == 'S') start = Point(row, col);
            if (ch == 'G') goal = Point(row, col);
            col++;
        }

        grid.push_back(rowData);
        row++;
    }

    file.close();
    return true;
}

void Maze::printMaze() const {
    for (const auto& row : grid) {
        for (char c : row) {
            std::cout << c << ' ';
        }
        std::cout << '\n';
    }
}

Point Maze::getStart() const {
    return start;
}

Point Maze::getGoal() const {
    return goal;
}

int Maze::getHeight() const {
    return grid.size();
}

int Maze::getWidth() const {
    return grid.empty() ? 0 : grid[0].size();
}

char Maze::getCell(int r, int c) const {
    if (r >= 0 && r < getHeight() && c >= 0 && c < getWidth()) {
        return grid[r][c];
    }
    return '#'; // Return wall for out-of-bounds
}

void Maze::setCell(int r, int c, char value) {
    if (r >= 0 && r < getHeight() && c >= 0 && c < getWidth()) {
        grid[r][c] = value;
    }
}
