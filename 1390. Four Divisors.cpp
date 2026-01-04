#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long res = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            int divisor_sum = 0, count = 0;
            int n = nums[j];
            for (long long i = 1; i*i <= n; i++)
            {
                if(i*i==n)
                {
                    divisor_sum += i;
                    count++;
                }
                else if(n%i==0)
                {
                    divisor_sum += i;
                    divisor_sum += n/i;
                    count += 2;
                }
                if(count>4) break;
            }
            if(count == 4) res += divisor_sum;
        }
        return res;
    }
};