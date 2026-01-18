#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMagicSquare(int i, int j, int k, vector<vector<int>>&prefixRowSum,vector<vector<int>>&prefixColumnSum,vector<vector<int>>&prefixMainDiagonalSum,vector<vector<int>>&prefixInverseDiagonalSum)
    {
        int refrence = prefixRowSum[i][j+k-1]-prefixRowSum[i][j-1];
        for(int l = i; l < i+k; l++) if(prefixRowSum[l][j+k-1]-prefixRowSum[l][j-1] != refrence) return false;
        for(int l = j; l < j+k; l++) if(prefixColumnSum[i+k-1][l]-prefixColumnSum[i-1][l] != refrence) return false;
        if(prefixMainDiagonalSum[i+k-1][j+k-1]-prefixMainDiagonalSum[i-1][j-1]!=refrence) return false;
        if(prefixInverseDiagonalSum[i+k-1][j]-prefixInverseDiagonalSum[i-1][j+k]!=refrence) return false;
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size(), columns = grid[0].size(), res = 1;
        vector<vector<int>> prefixRowSum(rows+1,vector<int>(columns+1,0));
        vector<vector<int>> prefixColumnSum(rows+1,vector<int>(columns+1,0));
        vector<vector<int>> prefixMainDiagonalSum(rows+1,vector<int>(columns+1,0));
        vector<vector<int>> prefixInverseDiagonalSum(rows+1,vector<int>(columns+1,0));
        for(int i = 1; i <= rows; i++) // Row
        {
            for(int j = 1; j <= columns; j++) prefixRowSum[i][j] = prefixRowSum[i][j-1]+grid[i-1][j-1];
        }
        for(int i = 1; i <= columns; i++) // Column
        {
            for(int j = 1; j <= rows; j++) prefixColumnSum[j][i] = prefixColumnSum[j-1][i]+grid[j-1][i-1];
        }
        for(int i = 1; i <= rows; i++) // Main Diagonal
        {
            for(int j = 1; j <= columns; j++) prefixMainDiagonalSum[i][j] = prefixMainDiagonalSum[i-1][j-1]+grid[i-1][j-1];
        }
        prefixInverseDiagonalSum[0].push_back(0);
        for(int i = 1; i <= rows; i++) // Inverse Diagonal
        {
            for(int j = 1; j < columns; j++) prefixInverseDiagonalSum[i][j] = prefixInverseDiagonalSum[i-1][j+1]+grid[i-1][j-1];
            prefixInverseDiagonalSum[i][columns]=grid[i-1][columns-1];
            prefixInverseDiagonalSum[i].push_back(0);
        }
        for(int i = 1; i <= rows; i++)
        {
            for(int j = 1; j<=columns; j++)
            {
                for(int k = 2; k <= min(rows-i+1,columns-j+1) ; k++)
                {
                    if(isMagicSquare(i,j,k,prefixRowSum,prefixColumnSum,prefixMainDiagonalSum,prefixInverseDiagonalSum)) res = max(res,k);
                }
            }
        }
        return res;
    }
};