#include "Maze_501492.h"
#include "Solver_501492.h"
#include <iostream>
#include <string>
using namespace std;


int main() {
    string filename;
    cout << "Enter maze CSV filename: ";
    cin >> filename;

    Maze maze;
    if (!maze.loadFromFile(filename)) {
        cerr << "Failed to load maze.\n";
        return 1;
    }

    cout << "\nInitial Maze:\n";
    maze.printMaze();

    Solver solver;
    bool solved = solver.solve(maze);

    if (solved) {
        cout << "\nSolved Maze:\n";
        maze.printMaze();
        cout << "\nParent array written to parent_array_output.csv\n";
    } else {
        cout << "\nNo solution found for this maze.\n";
    }

    return 0;
}
