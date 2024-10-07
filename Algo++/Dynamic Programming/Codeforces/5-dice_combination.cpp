#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; //cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> dp(n+1, 0);
		dp[n] = 1;
		for(int i = n-1; i >= 0; i--) {
			for(int j = 1; j <= 6; j++) {
				if(i+j > n) continue;
				dp[i] += dp[i+j] % MOD;
			}
		}
		cout << dp[0] % MOD << endl;
	}
}