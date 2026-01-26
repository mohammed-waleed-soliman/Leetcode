#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mn_difference = INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i = 0; i < arr.size()-1; i++) mn_difference = min(mn_difference,arr[i+1]-arr[i]);
        vector<vector<int>>res;
        for(int i = 0; i < arr.size()-1; i++) if(arr[i+1]-arr[i]==mn_difference) res.push_back({arr[i],arr[i+1]});
        return res;
    }
};