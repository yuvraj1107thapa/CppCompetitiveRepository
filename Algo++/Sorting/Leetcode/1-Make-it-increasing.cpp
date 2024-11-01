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
		vector<long long> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		int count = 0;
		bool possible = true;
		for(int i = n-2; i >= 0; i--) {
			if(a[i] >= a[i+1] && a[i+1] == 0) {
				possible = false;
				break;
			}
			while(a[i] >= a[i+1]) {
				a[i] /= 2;
				count++;
			}
		}
		
		cout << (possible ? count : -1) << endl;
	}
}