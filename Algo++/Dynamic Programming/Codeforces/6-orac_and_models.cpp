#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<long long> s(n);
		for(auto &i: s) cin >> i;
		vector<int> dp(n, 1);
		for(int i = n-1; i >= 0; i--) {
			for(int j = 2*(i+1); j <= n; j += (i+1)) {
				if(s[j-1] <= s[i]) continue;
				dp[i] = max(dp[i], 1 + dp[j-1]);
			}
		}
		cout << *max_element(dp.begin(), dp.end())<< endl;
	}
}