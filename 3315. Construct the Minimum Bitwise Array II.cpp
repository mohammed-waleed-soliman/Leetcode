#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(auto num:nums)
        {
            if(num == 2)
            {
                res.push_back(-1);
                continue;
            }
            int count = 0;
            while(num&1)
            {
                count++;
                num >>= 1;
            }
            num <<= 1;
            count--;
            while(count--)
            {
                num <<= 1;
                num |= 1;
            }
            res.push_back(num);
        }
        return res;
    }
};