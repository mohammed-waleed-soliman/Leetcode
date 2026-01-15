#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int x = 2, y = 2;
        int z = 2;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        for(int i = 0; i < hBars.size()-1; i++)
        {
            if(hBars[i]+1==hBars[i+1])
            {
                z++;
                x = max(x,z);
            }
            else z = 2;
        }
        z = 2;
        for(int i = 0; i < vBars.size()-1; i++)
        {
            if(vBars[i]+1==vBars[i+1])
            {
                z++;
                y = max(y,z);
            }
            else z = 2;
        }
        return min(x,y)*min(x,y);
    }
};