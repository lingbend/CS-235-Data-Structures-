#include <iostream>
#include "Grid.h"
#include <vector>
#include <fstream>
using std::vector, std::ifstream, std::cout, std::ofstream;

bool find_path(Grid& maze, vector<vector<int>>& path, int row, int col, int lev) {
    vector<int> entry = {row, col, lev};
    path.push_back(entry);
    if (maze.width() <= col || maze.height() <= row || maze.depth() <= lev || col < 0 || row < 0 || lev < 0 || maze.at(row, col, lev) == 2 || maze.at(row, col, lev) == 0) {
        path.pop_back();
        return false;
    }
    else if (col == maze.width() - 1 && row == maze.height() - 1 && lev == maze.depth() - 1) {
        return true;
    }
    maze.at(row, col, lev) = 2;
    if (find_path(maze, path, row - 1, col, lev) || find_path(maze, path, row + 1, col, lev) || find_path(maze, path, row, col - 1, lev)
    || find_path(maze, path, row, col + 1, lev) || find_path(maze, path, row, col, lev - 1) || find_path(maze, path, row, col, lev + 1)) {
        return true;
    }
    else {
        path.pop_back();
        return false;
    }
}

int main(int argc, char* argv[]) {
    vector<vector<int>> path;
    Grid maze;
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    infile >> maze;
    if (find_path(maze, path, 0, 0, 0)) {
        outfile << "SOLUTION" << std::endl;
        for (int i = 0; i < path.size(); i++) {
            outfile << path.at(i)[0] << " " <<path.at(i)[1] << " " << path.at(i)[2] << std::endl;
        }
    }
    else {
        outfile << "NO SOLUTION" << std::endl;
        exit;
    }

    return 0;
}
