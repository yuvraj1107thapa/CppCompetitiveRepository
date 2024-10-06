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
		for(auto& i: a) 
			cin >> i;
		long long ans = 0;
		
		int i = 0, j = 0;
		long long sum = 0;
		while(j < n) {
			sum += a[j];
			while(i <= j && sum > s) {
				sum -= a[i];
				i++;
			}
			if(sum <= s) {
				int c = j-i+1;
				ans += (1LL * c * (c+1) / 2);
			}
			j++;
		}
		
		cout << ans << endl;
	}
}