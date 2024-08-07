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
		long long n, s, m;
		cin >> n >> s >> m;
		vector<pair<int, int>> intervals;
		for(int i = 0; i < n; i++) {
			int l, r;
			cin >> l >> r;
			intervals.push_back({l, r});
		}
		int free_time = 0;
		free_time = intervals[0].first - 0;
		for(int i = 1; i < n; i++) {
			free_time = max(free_time, intervals[i].first - intervals[i-1].second);
			if(free_time >= s) {
				break;
			}
		}
		free_time = max(free_time, m - intervals[n-1].second);
		// cout << free_time << endl;
		cout << (free_time >= s ? "YES" : "NO") << endl;
	}
}