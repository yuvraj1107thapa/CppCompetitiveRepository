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
		int n, x;
		cin >> n >> x;
		vector<int> c(n);
		for(auto &i: c) cin >> i;
		vector<int> dp(x+1, INF);
		dp[0] = 0;
		for(int i = 1; i <= x; i++) {
			for(int j = 0; j < n; j++) {
				if(i-c[j] < 0) continue;
				dp[i] = min(dp[i], dp[i-c[j]] + 1);
			}
		}
		cout << (dp[x] == INF ? -1 : dp[x]) << endl;
	}
}