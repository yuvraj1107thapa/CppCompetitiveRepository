#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

vector<vector<int>> dp;

int solve(int i, int P, vector<int>& a, int n) {
	if(i >= n) return 0;
	if(dp[i][P] != -1) return dp[i][P];
	int ans = INF;
	if(P == 0) { // friend's turn
		int skip = 0;
		if(a[i] == 1) skip = 1;
		ans = min(ans, solve(i+1, 1, a, n) + skip);
		if(i+1 < n) {
			if(a[i+1] == 1) skip++;
			ans = min(ans, solve(i+2, 1, a, n) + skip);
		}
	}
	if(P == 1) { // my turn
		ans = min(ans, solve(i+1, 0, a, n));
		if(i+1 < n) {
			ans = min(ans, solve(i+2, 0, a, n)); 
		}
	}
	return dp[i][P] = ans;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<int> a(n); for(auto &i: a) cin >> i;
		dp.assign(n + 1, vector<int>(2, -1));
		cout << solve(0, 0, a, n) << endl;
	}
}