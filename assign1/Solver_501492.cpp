#include "Solver_501492.h"
#include <fstream>
#include <iostream>
#include <stack>
#include <queue>

// Directions: up, right, down, left
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

bool Solver::isValidMove(const Maze& maze, int r, int c) {
    return (r >= 0 && r < maze.getHeight() &&
            c >= 0 && c < maze.getWidth() &&
            maze.getCell(r, c) != '#' &&
            !visited[r][c]);
}

bool Solver::solve(Maze& maze) {
    int rows = maze.getHeight();
    int cols = maze.getWidth();

    visited.assign(rows, std::vector<bool>(cols, false));
    parent.assign(rows, std::vector<Point>(cols, Point(-1, -1)));

    Point start = maze.getStart();
    Point goal = maze.getGoal();

    std::stack<Point> stack;
    stack.push(start);
    visited[start.row][start.col] = true;
    
    while (!stack.empty()) {
        Point current = stack.top();
        stack.pop();
        
        // Check if reached the goal
        if (current.row == goal.row && current.col == goal.col) {
            reconstructPath(maze, start, goal);
            writeParentArrayToCSV("parent_array_output.csv");
            return true;
        }
        
        // Try all four directions
        for (int i = 0; i < 4; i++) {
            int newRow = current.row + dr[i];
            int newCol = current.col + dc[i];
            
            if (isValidMove(maze, newRow, newCol)) {
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = current;
                stack.push(Point(newRow, newCol));
            }
        }
    }
    
    return false; // No path found
}

void Solver::reconstructPath(Maze& maze, const Point& start, const Point& goal) {
    Point current = goal;
    
    while (!(current.row == start.row && current.col == start.col)) {
        // Don't mark start and goal
        if (maze.getCell(current.row, current.col) != 'S' && 
            maze.getCell(current.row, current.col) != 'G') {
            maze.setCell(current.row, current.col, '*');
        }
        
        current = parent[current.row][current.col];
    }
}

void Solver::writeParentArrayToCSV(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file for writing parent array.\n";
        return;
    }
    
    int rows = parent.size();
    int cols = rows > 0 ? parent[0].size() : 0;
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            file << "(" << parent[r][c].row << "," << parent[r][c].col << ")";
            if (c < cols - 1) file << ",";
        }
        file << "\n";
    }
    
    file.close();
}
