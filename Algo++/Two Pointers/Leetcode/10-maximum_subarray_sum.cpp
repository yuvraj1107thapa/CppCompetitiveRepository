
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
		int n, a, b;
		vector<long long> x(n);
		for(auto& i: x)
			cin >> i;
		int i = 0, j = 0;
		long long sum = 0;
		while(j < n) {
			sum += x[j];
			while(i <= j && j-i+1 >= b-a+1) {
				
				sum -= x[j];
				i++;
			}
		}
	}
}