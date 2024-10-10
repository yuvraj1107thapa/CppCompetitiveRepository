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
		int n, m;
		cin >> n >> m;
		
		int sum = n + m;
		vector<int> mul;
		int it = 5;
		while(it <= sum) {
			mul.push_back(it);
			it += 5;
		}
		
		if(mul.size() == 0) {
			cout << 0 << endl;
			continue;
		}
		
		int c = 0;
		for(int i = 1; i <= n; i++) {
			if(i % 5 == 0) {
				c += mul.size()-1;
				continue;
			}
			
			int index = -1;
			int l = 0, r = mul.size()-1;
			while(l <= r) {
				int mid = (l+r) / 2;
				if(mul[mid] - i >= 1 && mul[mid] - i <= m) {
					index = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			
			int index2 = -1;
			l = l, r = mul.size()-1;
			while(l <= r) {
				int mid = (l+r) / 2;
				if(mul[mid] - i >= 1 && mul[mid] - i <= m) {
					index2 = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			
			if(index != -1) {
				c += (index - index2 + 1);
			}
		}
		cout << c << endl;
	}
}