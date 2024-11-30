#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool check(vector<long long> &k, long long x, long long t) {
	long long tasks = 0;
	for(int i = 0; i < k.size(); i++) {
		tasks += x / k[i];
		if(tasks >= t) return true;
	}
	if(tasks >= t) return true;
	return false;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; //cin >> tc;
	while (tc--) {
		long long n, t;
		cin >> n >> t;
		vector<int> k(n);
		for(auto& i: k) 
			cin >> i;
		sort(k.begin(), k.end());
		long long ans = INF;
		long long l = 0, r = INF;
		while(l <= r) {
			long long mid = (l+r) / 2;
			if(check(k, mid, t)) {
				ans = mid;
				r = mid - 1;			
			}
			else l = mid + 1;
		}
		cout << ans << endl;
	}
}