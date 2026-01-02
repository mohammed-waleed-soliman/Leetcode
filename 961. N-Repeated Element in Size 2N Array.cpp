#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int>frequancy(1e4+1,0);
        int n = nums.size()/2;
        for(int i = 0; i < n*2; i++)
        {
            frequancy[nums[i]]++;
            if(frequancy[nums[i]]==n) return nums[i];
        }
        return 0;
    }
};