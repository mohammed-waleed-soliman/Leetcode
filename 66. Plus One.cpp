#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>res;
        bool flag = true;
        for(int i = digits.size()-1; i >= 0; i--)
        {
            if(digits[i]==9 && flag)
            {
                res.push_back(0);
            }
            else if(flag)
            {
                res.push_back(digits[i]+1);
                flag = false;
            }
            else
            {
                res.push_back(digits[i]);
            }
        }
        if(flag) res.push_back(1);
        reverse(res.begin(),res.end());
        return res;
    }
};