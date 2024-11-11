#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool check(vector<int> &a, long double x, int k) {
	int cuts = 0;
	for(auto i: a) {
		cuts += (long double)(i / x);
		if(cuts >= k) return true;
	}
	if(cuts >= k) return true;
	return false;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; //cin >> tc;
	while (tc--) {
		int n; long double k;
		cin >> n >> k;
		vector<int> a(n);
		for(auto &i: a) 
			cin >> i;
		long double ans = 0;
		long double l = 0, r = INF;
		for(int i = 0; i < 200; i++) {
			long double mid = (l + r) / 2;
			if(check(a, mid, k)) {
				ans = mid;
				l = mid;
			} 
			else r = mid;
		}
		cout << setprecision(10) << ans << endl;
	}
}