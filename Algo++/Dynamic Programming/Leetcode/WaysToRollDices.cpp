class Solution {
public:
    vector<vector<int>> dp;
    int solve(int n, int k, int target) {
        if(n == 0 and target > 0) return 0;
        if(target == 0 and n > 0) return 0;
        if(target == 0 and n == 0) return 1;
        if(dp[n][target] != -1) return dp[n][target];
        int ways = 0;
        for(int j = 1; j <=k; j++) {
            if(target-j >= 0) {
                ways = (ways + solve(n-1, k, target-j)) % 1000000007;
            }
        }
        return dp[n][target] = ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1, vector<int>(target+1, -1));
        return solve(n, k, target);
    }
};