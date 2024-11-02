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
		vector<long long> a(n);
		for(auto &i: a)
			cin >> i;
		
		vector<long long> forward(n), backward(n);
		
		// forward
		forward[0] = 1;
		for(int i = 1; i < n-1; i++) {
			if(abs(a[i+1] - a[i]) < abs(a[i-1] - a[i])) 
				forward[i] = 1;
			else
				forward[i] = abs(a[i+1] - a[i]);
		}
		forward[n-1] = 0;
		
		// backward
		backward[n-1] = 1;
		for(int i = n-2; i > 0; i--) {
			if(abs(a[i-1] - a[i]) < abs(a[i+1] - a[i])) 
				backward[i] = 1;
			else
				backward[i] = abs(a[i-1] - a[i]);
			
		}
		backward[0] = 0;
			
		// suffix and prefix sum
		for(int i = n-2; i >= 0; i--) {
			forward[i] = forward[i] + forward[i+1];
		}
		
		for(int i = 1; i < n; i++) {
			backward[i] = backward[i] + backward[i-1];
		}
		
		// m queries
		int m;
		cin >> m;
		while(m--) {
			int x, y;
			cin >> x >> y;
			if(x < y) {
				cout << abs(forward[x-1] - forward[y-1]) << endl;
			} 
			else if(x > y) {
				cout << abs(backward[x-1] - backward[y-1]) << endl;
			} 
			else {
				cout << 0 << endl;
			}
		}
	}
}