// Problem Link: https://leetcode.com/problems/out-of-boundary-paths

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    int dp[51][51][51];
    int dfs(int mm, vector<vector<int>> &grid, int i, int j) {
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size()) return 1;
        if(mm == 0) return 0;
        if(dp[i][j][mm] != -1) return dp[i][j][mm];
        long long path = 0;
        path = path + (dfs(mm-1, grid, i+1, j)%mod);
        path = path + (dfs(mm-1, grid, i-1, j)%mod);
        path = path + (dfs(mm-1, grid, i, j+1)%mod);
        path = path + (dfs(mm-1, grid, i, j-1)%mod);
        return dp[i][j][mm] = path%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        memset(dp, -1, sizeof dp);
        return dfs(maxMove, grid, startRow, startColumn);
    }
};