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
		int n, k;
		cin >> n >> k;
		vector<int> primes(n+1000, 1), p;
		for(int i = 2; i <= n+1000; i++) {
			if(primes[i] && i <= n) p.push_back(i);
			for(int j = i*2; j <= n; j+=i) {
				primes[j] = 0;
			}
		}
		int c = 0;
		for(int i = 0; i < p.size()-1; i++) {
			int sum = p[i] + p[i+1] + 1;
			if(sum <= n && primes[sum]) {
				c++;
			}
		}
		cout << (c >= k ? "YES" : "NO") << endl;
	} 
}