// Problem Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPresent(vector<int>& nums, int st, int end, int key) {
        while(st <= end) {
            int mid = (st+end)/2;
            if(nums[mid] == key) {
                return true;
            } else if(nums[mid] < key) {
                st++;
            } else {
                end--;
            }
        }
        return false;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            if(i != 0 and nums[i] == nums[i-1]) continue;
            if(isPresent(nums, i+1, nums.size()-1, k+nums[i])) {
                ans++;
            }
        }
        return ans;
    }
};