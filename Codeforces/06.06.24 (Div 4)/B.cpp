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
		int a1, a2, b1, b2;
		cin >> a1 >> a2 >> b1 >> b2;
		if(a1 > b1 && a1 > b2 && a2 > b1 && a2 > b2) {
			cout << 4 << endl;
		}
		else if(b1 > a1 && b1 > a2 && b2 > a1 && b2 > a2) {
			cout << 0 << endl;
		}
		else if((a1 > b1 && a2 > b2) || (a1 > b2 && a2 > b1))  {
			cout << 2 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}