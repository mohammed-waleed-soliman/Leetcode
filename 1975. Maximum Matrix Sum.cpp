#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int a = matrix.size(), b = matrix[0].size(), count = 0, mn = INT_MAX;
        bool cond = true;
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                int val = matrix[i][j];
                if(val<0)
                {
                    res += -1*val;
                    count++;
                    mn = min(mn,-1*val);
                }
                else if(val>0)
                {
                    res += val;
                    mn = min(mn,val);
                }
                else cond = false;
            }
        }
        if((count&1) && cond) res -= 2*mn;
        return res;
    }
};