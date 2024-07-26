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
		vector<int> a(n);
		for(auto &i: a) {
			cin >> i;
		}
		if(a[0] == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}