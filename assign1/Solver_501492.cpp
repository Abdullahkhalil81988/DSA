#include "Solver_501492.h"
#include <fstream>
#include <iostream>
using namespace std;

// check if a move is valid in the maze
bool Solver::isValidMove(const Maze& maze, int r, int c) {
    return (r >= 0 && r < maze.getHeight() &&
            c >= 0 && c < maze.getWidth() &&
            maze.getCell(r, c) != '#' &&
            !visited[r][c]);
}

// solve the maze using depth first search
bool Solver::solve(Maze& maze) {
    int rows = maze.getHeight();
    int cols = maze.getWidth();

    // initialize tracking arrays
    visited.assign(rows, vector<bool>(cols, false));
    parent.assign(rows, vector<Point>(cols, Point(-1, -1)));

    Point start = maze.getStart();
    Point goal = maze.getGoal();

    //  use stack for depth first search 
    stack<Point> st;
    st.push(start);
    visited[start.row][start.col] = true;

    // direction arrays for moving in 4 directions
    int dr[] = {-1, 1, 0, 0}; // up, down, left, right
    int dc[] = {0, 0, -1, 1};

    bool found = false;

    while (!st.empty()) {
        Point curr = st.top();
        st.pop();

        if (curr.row == goal.row && curr.col == goal.col) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + dr[i];
            int nc = curr.col + dc[i];

            if (isValidMove(maze, nr, nc)) {
                visited[nr][nc] = true;
                parent[nr][nc] = curr;
                st.push(Point(nr, nc));
            }
        }
    }

    if (found) {
        reconstructPath(maze, start, goal);
        writeParentArrayToCSV("parent_array_output.csv");
    }

    return found;
}

// mark the solution path in the maze
void Solver::reconstructPath(Maze& maze, const Point& start, const Point& goal) {
    Point curr = goal;
    while (!(curr.row == start.row && curr.col == start.col)) {
        if (maze.getCell(curr.row, curr.col) != 'G')
            maze.setCell(curr.row, curr.col, '*');
        curr = parent[curr.row][curr.col];
    }
}

// save parent links to a csv file for debugging
void Solver::writeParentArrayToCSV(const string& filename) {
    ofstream file(filename);
    for (const auto& row : parent) {
        bool first = true;
        for (const auto& p : row) {
            if (!first) file << ",";
            file << "(" << p.row << "," << p.col << ")";
            first = false;
        }
        file << "\n";
    }
    file.close();
}
