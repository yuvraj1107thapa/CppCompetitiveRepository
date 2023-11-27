class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[101][101] = {0};
        for(auto x: strs){
            int count_m = count(x.begin(), x.end(), '0');
            int count_n = x.size() - count_m;
            for(int i = m; i >= count_m; i--){
                for(int j = n; j >= count_n; j--){
                    if(i >= count_m and j >= count_n){
                        dp[i][j] = max(dp[i][j], 1 + dp[i-count_m][j-count_n]);
                    }
                }
            }   
        }
        return dp[m][n];
    }
};