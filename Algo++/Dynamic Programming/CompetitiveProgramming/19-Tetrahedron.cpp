#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; // cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		
		int dp[10000010][4];
		
		dp[0][0] = 0;
		dp[0][1] = 0;
		dp[0][2] = 0;
		dp[0][3] = 1;
		
		for(int i = 1; i <= n; i++) {
			long long sum = 1ll * dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3];
			for(int j = 0; j < 4; j++) {
				dp[i][j] = ((sum - dp[i-1][j]) % MOD + MOD) % MOD;
			}
		}
		
		cout << dp[n][3] << endl;
	}
}