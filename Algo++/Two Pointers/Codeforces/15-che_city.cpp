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
		long long n, r;
		cin >> n >> r;
		vector<long long> d(n);
		for(auto& i: d) 
			cin >> i;
		long long c = 0;
		int i = 0, j = 0;
		while(j < n) {
			while(i <= j && d[j]-d[i] > r) {
				c += (n-j);
				i++;
			}
			j++;
		}
		cout << c << endl;
	}
}

/*
Count pairs s.t. diff b/n them is greater than r
*/