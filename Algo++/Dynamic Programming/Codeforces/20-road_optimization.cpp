#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n, l, k;
    cin >> n >> l >> k;
    
    vector<int> d(n+1), a(n);
    for(int i = 0; i < n; i++) {
    	cin >> d[i];
    }
    
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(k+1, INF));
    
    for(int j = 0; j <= k; j++) {
        dp[n-1][j] = 0;
    }
    
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j <= k; j++) {
            for(int p = 1; i+p <= n && p-1 <= j; p++) {
                dp[i][j] = min(dp[i][j], dp[i+p][k-(p-1)] + (d[i+p] - d[i]) * a[i]);
            }
        }
    }
    
    cout << dp[0][k] << endl;
}