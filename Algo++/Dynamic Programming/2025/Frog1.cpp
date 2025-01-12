#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

const int MAX_N = 1e5+1;
int dp[MAX_N];

int solve(int n, vector<int>& a) {
	if(dp[n] != -1) return dp[n];
	if(n < 0) return INF;
	if(n == 0) return 0;
	int ans = INF;
	if(n >= 1) 
		ans = min(ans, solve(n-1, a) + abs(a[n]-a[n-1]));
	if(n >= 2) 
		ans = min(ans, solve(n-2, a) + abs(a[n]-a[n-2]));
	return dp[n] = ans;		
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; //cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<int> a(n); for(auto &i: a) cin >> i;
		memset(dp, -1, sizeof dp);
		cout << solve(n-1, a) << endl;
	}
}