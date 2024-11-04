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
		int n, m, q; 
		cin >> n >> m >> q;
		int x, y; 
		cin >> x >> y;
		int s; 
		cin >> s;
		if((x <= s && y >= s) || (x >= s && y <= s)) 
			cout << abs(x-y)/2 << endl;
		else if(x > s && y > s)
			cout << s-1 + min(abs(x-s), abs(y-s)) << endl;
		else if(x < s && y < s)
			cout << n-s + min(abs(x-s), abs(y-s)) << endl;
	}
}