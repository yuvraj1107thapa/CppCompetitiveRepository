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
		if(n % 2 == 0) {
			int c = n / 2;
			cout << c << endl;
			for(int i = 0; i < c; i++) {
				cout << 2 << " ";	
			}
		}
		else {
			int c = n / 2;
			cout << c << endl;
			for(int i = 0; i < c-1; i++) {
				cout << 2 << " ";	
			}
			cout << 3;
		}
	}
}