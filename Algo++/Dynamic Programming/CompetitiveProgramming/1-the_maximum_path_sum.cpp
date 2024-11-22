#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int f(int i, int j, int n, int m, vector<vector<int>>& arr) {
	if(i == n-1 && j == m-1) {
		return arr[i][j];
	}
	if(i == n || j == m) {
		return -INF;
	}
	int down = f(i+1, j, n, m, arr);
	int right = f(i, j+1, n, m, arr);
	return max(down, right) + arr[i][j];
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; // cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> arr(n, vector<int> (m));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		
		cout << f(0, 0, n, m, arr);
	}
}