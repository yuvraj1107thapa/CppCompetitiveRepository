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
		long long n;
		cin >> n;
		vector<int> dollars({1,5,10,20,100});
		
		vector<int> dp(n+1, INF);
		dp[0] = 0;
		for(auto d: dollars) dp[d] = 1;
		
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < dollars.size(); j++) {
				if(dollars[j] > i) break;
				dp[i] = min(dp[i], 1 + dp[i-dollars[j]]);
			}
		}
		
		cout << dp[n] << endl;
	}
}