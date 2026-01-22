#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSorted(vector<int>& nums)
    {
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while(!isSorted(nums))
        {
            int ind = 0, mn = INT_MAX;
            for(int i = 0; i < nums.size()-1; i++)
            {
                if(nums[i]+nums[i+1]<mn)
                {
                    ind = i;
                    mn = nums[i]+nums[i+1];
                }
            }
            int sum = nums[ind]+nums[ind+1];
            nums.erase(nums.begin()+ind,nums.begin()+ind+2);
            nums.insert(nums.begin()+ind,sum);
            count++;
        }
        return count;
    }
};