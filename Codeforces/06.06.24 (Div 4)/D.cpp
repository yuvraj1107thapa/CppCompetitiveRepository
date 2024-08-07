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
		string s, t;
		cin >> s >> t;
		if(t.size() > s.size()) {
			cout << "NO" << endl;
			continue;
		}
		int n = s.size(), m = t.size();
		string ans = "";
		
		int i = 0, j = 0;
		while(i < n && j < m) {
			if(s[i] == '?' || s[i] == t[j]) {
				ans += t[j];
				i++;
				j++;
			}
			else {
				while(i < n && s[i] != t[j] && s[i] != '?') {
					ans += s[i];
					i++;
				}
				if(i < n && s[i] == t[j] || s[i] == '?') {
					ans += t[j];
					i++;
					j++;
				}
				else {
					break;
				}
			}
		}
		
		if(j == m) { 
			while(i < n) {
				if(s[i] == '?') {
					ans += 'a';
				}
				else {
					ans += s[i];
				}
				i++;
			}	
			cout << "YES" << endl << ans << endl;	
		}
		else {
			cout << "NO" << endl;
		}
	}
}