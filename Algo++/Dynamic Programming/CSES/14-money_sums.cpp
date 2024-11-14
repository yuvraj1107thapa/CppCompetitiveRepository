#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; 
	// cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> x(n);
		for(int i = 0; i < n; i++) {
			cin >> x[i];
		}
		
		set<int> s;
		s.insert(x[0]);
		
		for(int i = 1; i < n; i++) {	
			set<int> temp;
			for(auto sum: s) {
				temp.insert(sum + x[i]);
			}
			s.insert(x[i]);
			s.insert(temp.begin(), temp.end());
		}
		
		cout << s.size() << endl;
		for(auto sum: s) {
			cout << sum << " ";
		}
	}
}