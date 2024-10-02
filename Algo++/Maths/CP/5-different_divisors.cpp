#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	const int M = 1e6;
	vector<int> primes(M, 1);
	for(int i = 2; i < M; i++) {
		for(int j = 2*i; j < M; j += i) {
			primes[j] = 0;
		}
	}
	
	int tc; cin >> tc;
	while (tc--) {
		int d;
		cin >> d;
		int ans = 1;
		int p = -1, q = -1; 
		int i = 2;
		while(i < M) {
			if(primes[i]) {
				if(i - ans >= d) {
					if(p == -1) {
						p = i;
						ans *= p;
					}
					else {
						q = i;
						ans *= q;
					break;
				}
				}
			}
			i++;
		}
		cout << ans << endl;
	}
}