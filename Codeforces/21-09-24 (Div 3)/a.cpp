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
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for(auto &i: arr) cin >> i;
		int ans = 0, gold = 0;
		for(auto i: arr) {
			if(i >= k)
				gold += i;
			else if(i == 0 && gold > 0) {
				gold -= 1;
				ans++;
			}
		}
		cout << ans << endl;
	}
}