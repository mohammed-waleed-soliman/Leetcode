#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int r = mat.size(), c = mat[0].size(), res = 0;
        vector<vector<int>>prefix(r+1,vector<int>(c+1,0));
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                prefix[i][j] = mat[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
        }
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                for(int k = 1; k <= min(r-i+1,c-j+1); k++)
                {
                    if(prefix[i+k-1][j+k-1]-prefix[i-1][j+k-1]-prefix[i+k-1][j-1]+prefix[i-1][j-1]<= threshold) res = max(res,k);
                    else break;
                }
            }
        }
        return res;
    }
};