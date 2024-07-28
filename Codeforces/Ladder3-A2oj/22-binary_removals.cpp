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
		string s;
		cin >> s;
		
		int n = s.size();
		bool flag = true;
		bool two_ones = false;
		for(int i = 1; i < n; i++) {
			if(two_ones && s[i] == '0' && s[i-1] == '0') {
				flag = false;
				break;
			}
			if(two_ones == false && s[i] == '1' & s[i-1] == '1') {
				two_ones = true;
			}
 		}
		if(flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

// After 11 --> There should be No 00