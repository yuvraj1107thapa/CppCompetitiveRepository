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
		long long n, s;
		cin >> n >> s;
		vector<long long> a(n);
		for(auto &i: a) 
			cin >> i;
		int i = 0, j = 0;
		long long sum = 0;
		long long c = 0;
		while(j < n) {
			sum += a[j];
			while(i <= j && sum >= s) {
				c += n-j;
				sum -= a[i];
				i++;
			}
			j++;
		}
		cout << c << endl;
	}
}