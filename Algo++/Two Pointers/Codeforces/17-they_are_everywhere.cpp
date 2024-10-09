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
		string s;
		cin >> s;
		int ans = INF;
		set<char> st;
		for(int i = 0; i < s.size(); i++) {
			st.insert(s[i]);
		}
		int distinct = st.size();
		map<char, int> m;
		int i = 0, j = 0;
		while(j < n) {
			char c = s[j];
			m[c]++;
			while(i <= j && m.size() >= distinct) {
				ans = min(ans, j-i+1);
				char t = s[i];
				m[t]--;
				if(m[t] == 0) m.erase(t);
				i++;
			}
			j++;
		}
		cout << ans << endl;
	}
}