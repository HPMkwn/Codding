#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

/**
 * Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, 
 * return the number of negative numbers in grid.
 * [[4,3,2,-1],
 *  [3,2,1,-1],
 *  [1,1,-1,-2],
 *  [-1,-1,-2,-3]]
 */

int countNegatives(vector<vector<int>>& grid) {
    int row = 0, col = grid[0].size() - 1;
    int m = grid.size(), n = grid[0].size();
    int count = 0;

    while (row < grid.size() && col >= 0) {
        if (grid[row][col] >= 0) {
            count += (n - 1 - col);
            row++;
        } else if (grid[row][col] < 0) {
            col--;
        }
    }

    if (row < m) count += (n * (m - row));

    return count;
}


int main() { return 0; }