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
		vector<int> v(n-1);
		long long sum = 0;
		for(auto& i: v) {
			cin >> i;
			sum += i;
		}
		long long sum_of_n = n * (n+1) / 2;
		cout << sum_of_n-sum << endl;
	}
}