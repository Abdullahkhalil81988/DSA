#include "Maze_501492.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

bool Maze::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open maze file.\n";
        return false;
    }

    string line;
    grid.clear();
    int row = 0;

    while (getline(file, line)) {
        vector<char> rowData;
        stringstream ss(line);
        string cell;
        int col = 0;

        while (getline(ss, cell, ',')) {
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
        for (char c : row) cout << c << ' ';
        cout << '\n';
    }
}
