#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void f(int n, vector<vector<int>>& ans) {
	if(n == 0) { ans.push_back({}); return; }
	f(n-1, ans);
	int k = ans.size();
	for(int i = 0; i < k; i++) {
		vector<int> subset = ans[i];
		subset.push_back(n);
		ans.push_back(subset);
	}
}

// vector<vector<int>> res;
// vector<int> subset;
// int N = 10;

// void search(int k) {
// 	if(k == N) { res.push_back(subset); return; } //process subset 
// 	else {
// 		search(k+1);
// 		subset.push_back(k);
// 		search(k+1);
// 		subset.pop_back();
// 	}	
// }

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<vector<int>> ans;
		f(n, ans);
		for(int i = 0; i < ans.size(); i++) {
			for(int j = 0; j < ans[i].size(); j++) {
				cout << ans[i][j] << " ";	
			}
			cout << endl;
		}
		
		// for (auto& vec : res) {
        //     for (int x : vec) {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
	}
}