#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool check(vector<pair<int,int>>& v, int x) {
	int n = v.size();
	int c = 0;
	for(int i = 0; i < n; i++) {
		int a = v[i].first, b = v[i].second;
		if(c <= b && x-c-1 <= a) c++;
		if(c >= x) return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<pair<int, int>> v;
		for(int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({a,b});
		}
		int ans = 0;
		int l = 0, r = n;
		while(l <= r) {
			int mid = (l+r) / 2;
			if(check(v, mid)) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << ans << endl;
	}
}

/*
Check if possible to invite 'x' person or not

Need to take x elements and satisy both conidition for all x simuntaneously
.....................................i.....................................
            <=bi                                          <=ai

- 1: 0 <= b1 && x-1 <= a1               [ x-1 as including the ith element ]
- 2: 1 <= b2 && x-2 <= a2
...
..
.
*/