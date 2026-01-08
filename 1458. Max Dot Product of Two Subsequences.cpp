#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size();
        int size2=nums2.size();
        vector<vector<long long>> dp(size1 + 1, vector<long long>(size2 + 1, INT_MIN));
        for(int i = 0; i <= size1; i++) dp[i][0]=INT_MIN;
        for(int i = 0; i <= size2; i++) dp[0][i]=INT_MIN;
        for(int i = 1; i <= size1; i++)
        {
            for(int j = 1; j <= size2; j++) dp[i][j] = max({nums1[i-1]*nums2[j-1]*1LL,dp[i][j-1],dp[i-1][j],nums1[i-1]*nums2[j-1]+dp[i-1][j-1]});
        }
        return dp[size1][size2];
    }
};