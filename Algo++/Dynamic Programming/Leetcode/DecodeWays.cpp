// Problem link: https://leetcode.com/problems/decode-ways
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int dp[106];
    int decodeWays(string str, int idx) {
        if(idx == 0 or idx == 1) return 1;
        if(dp[idx] != -1) return dp[idx];
        int ans = 0;
        if(str[idx-1]-'0' > 0) {
            ans += decodeWays(str, idx-1);
        }
        if(idx-2>=0 and str[idx-2]-'0' > 0 and (str[idx-2]-'0')*10 + (str[idx-1]-'0') <= 26) {
            ans += decodeWays(str, idx-2);
        } 
        return dp[idx] = ans;
    }
    
    int numDecodings(string s) {
        std::memset(dp, -1, sizeof dp);
        if(s[0] == '0') return 0;
        return decodeWays(s, s.size());
    }
};