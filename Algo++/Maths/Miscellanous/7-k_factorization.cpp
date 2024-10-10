#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; // cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<int> ans;
		
		for(int i = 2; i <= n; i++) {
			while(n % i == 0) {
				ans.push_back(i);
				n /= i;
			}
		}
		
		if(ans.size() == 1 && k == 1) {
			cout << ans[0] << endl;
			continue;
		} 
		
		if(ans.size() < k) {
			cout << -1 << endl;
		}
		
		else {
			int sum = 1;
			for(int i = 0; i < ans.size(); i++) {
				if(i+1 >= k) {
					sum *= ans[i];
				}
				else cout << ans[i] << " ";
			}
			cout << sum << endl;
		}
	}
}