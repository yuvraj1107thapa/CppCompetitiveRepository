#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool check(long double x, vector<pair<int, int>> &p) {
	int n = p.size();
	vector<pair<long double, long double>> range;
	for(int i = 0; i < n; i++) {
		int a = p[i].first, b = p[i].second;
		range.push_back({a - x * b, a + x * b});
	}
	long double l = range[0].first, r = range[0].second;
	for(int i = 1; i < n; i++) {
		long double li = range[i].first, ri = range[i].second;
		r = min(r, ri);
		l = max(l, li);	
		if(l > r) return false;
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; //cin >> tc;
	while (tc--) {
		long long n;
		cin >> n;
		vector<long long> x(n), v(n);
		for(auto &i : x) cin >> i;
		for(auto &i : v) cin >> i;
		vector<pair<int, int>> p;
		for(int i = 0; i < n; i++) {
			p.push_back({x[i], v[i]});
		}
		long double ans = INF;
		long double l = 0, r = INF;
		for(int i = 0; i < 200; i++) {
			long double mid = (double)(l+r) / 2;
			if(check(mid, p)) {
				ans = mid;
				r = mid;
			} 
			else l = mid;
		}
		cout << fixed << setprecision(12) << ans << endl;
	}
}