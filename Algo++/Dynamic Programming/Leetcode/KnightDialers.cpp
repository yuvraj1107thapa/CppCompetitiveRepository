class Solution {
public:
    int dp[5001][10];
    int mod = 1e9+7;
    int dfs(int n, vector<vector<int>> &v, int cell) {
        if(n == 0) return 1;
        if(dp[n][cell] != -1) return dp[n][cell];
        int ans = 0;
        for(int &nextCell: v[cell]) {
            ans = (ans + dfs(n-1, v, nextCell))%mod;
        }
        return dp[n][cell] = ans;
    }
    int knightDialer(int n) {
        if(n == 1) return 10;
        memset(dp, -1, sizeof dp);
        vector<vector<int>> v = {{4,6}, {6,8}, {7,9}, {8,4}, {9,3,0}, {}, {0,1,7}, {6,2}, {1,3}, {2,4}};
        int ans = 0;
        for(int i = 0; i <= 9; i++) {
            ans = (ans + dfs(n-1,v,i))%mod;
        }
        return ans % mod;
    }
};