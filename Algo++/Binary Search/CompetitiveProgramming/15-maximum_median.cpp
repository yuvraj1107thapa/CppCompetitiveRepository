#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool check(long long x, vector<long long> &a, int k) {
	int n = a.size();
	int c = 0;
	for(int i = n-1; i >= n/2; i--) {
		if(a[i] >= x) continue;
		c += (x-a[i]);
		if(c > k) return false;
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; //cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<long long> a(n);
		for(auto &i: a) cin >> i;
		sort(a.begin(), a.end());
		int l = a[0], r = a[n-1] + k;
		long long ans = r;
		while(l <= r) {
			long long mid = (l+r) / 2;
			if(check(mid, a, k)) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << ans << endl;
	}
}