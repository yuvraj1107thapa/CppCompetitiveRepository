#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; //cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for(auto &i: a) cin >> i;
		vector<vector<int>> ans(1, vector<int> (1, a[0]));
		for(int i = 1; i < n; i++) {
			int l = 0, r = ans.size()-1;
			int idx = -1;
			while(l <= r) {
				int mid = (l + r) / 2;
				int last = ans[mid][ans[mid].size()-1];
				if(last < a[i]) {
					idx = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			if(idx == -1) {
				vector<long long> v(1, a[i]);
				ans.push_back(v);
			}
			else ans[idx].push_back(a[i]);
		}	
		
		for(auto r: ans) {
			for(auto c: r) cout << c << " ";
			cout << endl;
		}
	}
}