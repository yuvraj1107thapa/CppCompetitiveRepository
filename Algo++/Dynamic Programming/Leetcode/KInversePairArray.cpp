// Problem link: https://leetcode.com/problems/k-inverse-pairs-array

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int mod=int(1e9+7);
    int dp[1001][1001];
    int f(int n,int k) {
        //base case
        if(k<=0) return k==0;
        if(dp[n][k]!=-1) return dp[n][k];


        int ans=0;
        for(int i=0;i<n;++i) {
            ans+=f(n-1,k-i);
            ans%=mod;
        }
        return dp[n][k]=ans;
    }
public:
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return f(n,k);
    }
};

/*
Intuition
Let's say we have n elements in our permutation then Depending on where we put the element (n+1) in our permutation, we may add 0, 1, 2, ..., n new inverse pairs. For example, if we have some permutation of 1...4, then:

5 x x x x creates 4 new inverse pairs
x 5 x x x creates 3 new inverse pairs
...
x x x x 5 creates 0 new inverse pairs
Approach
dp[n][k] = dp[n - 1][k - 0] + dp[n - 1][k - 1] + ... + dp[n - 1][k - (n - 1)]

Complexity
Time complexity: O(n∗k∗k)O(n*k*k)O(n∗k∗k) to O(n∗k)O(n*k)O(n∗k)

Space complexity:O(n∗k)O(n*k)O(n∗k) to O(k)O(k)O(k)
*/