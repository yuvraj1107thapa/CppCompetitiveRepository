#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	const int M = 2e5 + 10;
	vector<int> ops(M);
	for(int i = 0; i < M; i++) {
		ops[i] = 0;
		int x = i;
		while(x > 0) {
			ops[i] += 1;
			x /= 3;
		}
	}
	
	vector<int> pref(M + 1);
	for(int i = 0; i < M; i++) {
		pref[i+1] = pref[i] + ops[i];
	}
	
	int tc; cin >> tc;
	while (tc--) {
		int l, r;
		cin >> l >> r;
		int ans = 0;
		ans += ops[l];
		ans += ops[l+1]+ops[l];
		ans += pref[r] - pref[l+1];
		cout << ans << endl;
	}
}