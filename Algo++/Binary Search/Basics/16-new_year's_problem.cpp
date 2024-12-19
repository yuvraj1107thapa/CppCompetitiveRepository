#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool check(int x, vector<vector<int>>& p, int n, int m) {
	vector<int> v(n);
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			v[j] = max(v[j], p[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		if(v[i] < x) return false;
	}
	for(int i = 0; i < m; i++) {
		int c = 0;
		for(int j = 0; j < n; j++) {
			if(p[i][j] >= x) c++;
		}
		if(c >= 2) return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		int m, n;
		cin >> m >> n;
		vector<vector<long long>> p(m, vector<int>(n));
		long long mini = INF, maxi = -INF;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				cin >> p[i][j];
				mini = min(mini, p[i][j]);
				maxi = max(maxi, p[i][j]);
			}
		}
		
		int ans = mini;
		long long l = mini, r = maxi;
		while(l <= r) {
			int mid = (l+r) / 2;
			if(check(mid, p, n, m)) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << ans << endl;
	}
}