#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        map<int,bool>vis;
        for(int i = 0; i < nums.size(); i++)
        {
            int x = 0;
            for(int j = 0; j < nums[i].size(); j++)
            {
                if(nums[i][j]=='1') x += pow(2,nums[i].size()-j-1);
            }
            vis[x]=true;
        }
        int y = 0;
        while(vis[y]) y++;
        string res="";
        while(y)
        {
            if(y&1) res.push_back('1');
            else res.push_back('0');
            y /= 2;
        }
        while(res.size()<nums[0].size()) res.push_back('0');
        reverse(res.begin(),res.end());
        return res;
    }
};