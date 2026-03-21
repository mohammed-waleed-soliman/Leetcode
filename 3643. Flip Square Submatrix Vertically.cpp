#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = y; i < y+k; i++)
        {
            int p = x+k-1;
            for(int j = x; j < x+k/2; j++)
            {
                int temp = grid[j][i];
                grid[j][i] = grid[p][i];
                grid[p--][i] = temp;
            }
        }
        return grid;
    }
};