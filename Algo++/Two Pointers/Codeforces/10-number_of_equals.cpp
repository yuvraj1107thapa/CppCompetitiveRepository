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
		vector<long long> A(n), B(m);
		for(auto& i: A)
			cin >> i;
		for(auto& i: B)
			cin >> i;
		int c = 0;
		int i = 0, j = 0;
		while(i < n && j < m) {
			if(A[i] == B[j]) {
				long long element = B[j];
				int a = 0;
				while(i < n && A[i] == element) {
					i++;
					a++;
				}
				int b = 0;
				while(j < m && B[j] == element) {
					j++;
					b++;
				}
				c += (a * b);
			} else if(A[i] < B[j]){
				i++;
			} else {
				j++;
			}
		}
		cout << c << endl;
	}
}