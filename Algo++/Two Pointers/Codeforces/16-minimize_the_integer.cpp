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
		string a;
		cin >> a;
		int n = a.size();
		int e = -1, o = -1;
		for(int i = 0; i < n; i++) {
			if(((int)a[i]-'0') % 2 == 0) {
				e = i;
				break;
			}
		}
		for(int i = 0; i < n; i++) {
			if(((int)a[i]-'0') % 2 != 0) {
				o = i;
				break;
			}
		}
		if(e == -1 || o == -1) {
			cout << a << endl;
		} 
		else {
			string ans = "";
			vector<bool> c(n+1, false);
			while(e < n && o < n) {
				if(c[e] == false && o < n && a[e]-'0' < a[o]-'0') {
					ans += a[e];
					c[e] = true;
					bool flag = false;
					e++;
					for(int i = e; i < n; i++) {
						if(c[i] == false && ((int)a[i]-'0') % 2 == 0) {
							flag = true;
							e = i;
							break;
						}
						e = i;
					}
					if(flag == false) 
						break;
				}
				else {
					ans += a[o];
					c[o] = true;
					bool flag = false;
					o++;
					for(int i = o; i < n; i++) {
						if(c[i] == false && ((int)a[i]-'0') % 2 != 0) {
							flag = true;
							o = i;
							break;
						}
					}
					if(flag == false) 
						break;
				}
			}
			
			while(e < n) {
				if(c[e] == false && ((int)a[e]-'0') % 2 == 0) {
					ans += a[e];
				}
				e++;
			}
			
			while(o < n) {
				if(c[o] == false && ((int)a[o]-'0') % 2 != 0) {
					ans += a[o];
				}
				o++;
			}
			
			cout << ans << endl;
		}
	}
}