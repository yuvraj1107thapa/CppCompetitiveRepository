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
		vector<long long> d(n);
		for(auto &i: d) cin >> i;
		sort(d.begin(), d.end());
		int l = 0, r = d.size()-1;
		long long x = 1LL * d[l] * d[r];
		
		vector<long long> v;
		for(int i = 2; i*i <= x; i++) {
			if(x % i == 0) {
				v.push_back(i);
				if(i != (x/i)) {
					v.push_back(x/i);
				}
			}
		}
		
		if(v.size() != d.size()) {
			cout << -1 << endl;
		}
		else {
			bool flag = true;
			sort(v.begin(), v.end());
			for(int i = 0; i < n; i++) {
				if(d[i] != v[i]) {
					flag = false;
					break;
				}
			}
			cout << (flag == false ? -1 : x) << endl;
		}
	}
}