#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool contains(string& x, string& s) {
	if(x.size() < s.size()) return false;
	int size = s.size();
	for(int i = 0; i+size-1 < x.size(); i++) {
		string sub = x.substr(i, size);
		if(sub == s) {
			return true;
		}
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		string x, s;
		cin >> x >> s;
		int count = 0;
		int k = 6;
		bool flag = 0;
		while(k--) {
			if(contains(x, s)) {
				flag = 1;
				break;
			}
			x += x;
			count++;
		}
		if(flag == 1) {
			cout << count << endl;
		} else {
			cout << -1 << endl;
		}
	}
}