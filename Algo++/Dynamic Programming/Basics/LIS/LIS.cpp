// Problem link: https://leetcode.com/problems/longest-increasing-subsequence
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 1);
        for(int i=1; i<nums.size(); i++) {
            for(int j=0; j<=i-1; j++) {
                if(nums[j]<nums[i]) {
                    dp[i]=std::max(dp[i], dp[j]+1);
                }
            }
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};