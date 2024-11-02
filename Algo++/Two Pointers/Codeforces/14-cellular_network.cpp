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
		int n, m;
		cin >> n >> m;
		vector<long long> a(n), b(m);
		for(auto& i: a)
			cin >> i;
		for(auto& i: b)
			cin >> i;
		long long r = -INF;
		int i = 0, j = 0;
		while(i < n) {
			long long cl = abs(a[i] - b[j]);
			while(j < m-1 && abs(a[i] - b[j+1]) <= abs(a[i] - b[j])) {
				cl = min(cl, abs(a[i] - b[j+1]));
				j++;
			}
			r = max(r, cl);
			i++;
		}
		cout << r << endl;
	}
}