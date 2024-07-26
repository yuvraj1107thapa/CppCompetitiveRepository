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
		n--;
		vector<int> v(n);
		long long sum = 0;
		for(auto &i: v) {
			cin >> i;
			sum += i;
		}
		cout << -(sum) << endl;
	}
}