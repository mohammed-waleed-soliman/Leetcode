#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        long long MOD = 1e9+7;
        long long x = 6, y = 6;
        for(int i = 2; i <= n; i++)
        {
            long long a = (3*x + 2*y)%MOD;
            long long b = (2*x + 2*y)%MOD;
            x = a%MOD, y = b%MOD;
        }
        return (x+y)%MOD;
    }
};