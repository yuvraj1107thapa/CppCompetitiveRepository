class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        int max_square=0;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]=='0') continue;
                if(i==0 or j==0) {
                    dp[i][j]=1;
                }
                else if(matrix[i][j]=='1'){
                    dp[i][j]=1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                max_square=max(max_square, dp[i][j]);
            }
        }
        
        return max_square*max_square;
    }
};