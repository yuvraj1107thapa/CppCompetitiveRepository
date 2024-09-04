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
		int a, b;
		cin>>a>>b;
		int c = INF;
		for(int i = a; i <=b; i++) {
			c = min(c, (i-a) + (b-i));
		}
		cout << c << endl;
	}
}