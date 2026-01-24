#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int mn = 0;
        int size = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < size/2; i++) mn = max(mn,nums[i]+nums[size-1-i]);
        return mn;
    }
};