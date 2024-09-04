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
		vector<string> s(n);
		vector<int> ans;
		for(auto &i: s) cin >> i;
		for(int i = n-1; i >=0; i--) {
			for(int j = 0; j < 4; j++) {
				if(s[i][j] == '#') 
					ans.push_back(j+1);
			}
		}
		for(auto i: ans) cout << i << " ";
		cout << endl;
	}
}