#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.insert(hFences.begin(),1);
        vFences.insert(vFences.begin(),1);
        hFences.push_back(m);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_map<int,int>mp;
        for(int i = 0; i < hFences.size()-1; i++)
        {
            for(int j = i+1; j < hFences.size(); j++)
            {
                mp[hFences[j]-hFences[i]] = 1;
            }
        }
        long long res = -1;
        for(int i = 0; i < vFences.size()-1; i++)
        {
            for(int j = i+1; j < vFences.size(); j++)
            {
                if(mp[vFences[j]-vFences[i]]) res = max(res,(vFences[j]-vFences[i])*1LL);
            }
        }
        if(res<0) return res;
        else return (res*res)%MOD;
    }
};