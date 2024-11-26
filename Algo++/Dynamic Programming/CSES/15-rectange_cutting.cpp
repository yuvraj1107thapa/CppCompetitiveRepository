#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int dp[505][505];

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; 
	// cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		
		memset(dp, -1, sizeof dp);
		
	}
}
/*
Greedy fails...

Overlapping subproblem...

State: dp[n][m] = min cut require to cut n x m rectangle into squares

Transition: vertical => dp[i][j] = min(dp[i][k], dp[i][m-k]) + 1 for all k from 1 to m
			
			horizontal => dp[i][j] = min(dp[k][j], dp[n-k][j]) + 1 for all k from 1 to n
			
			min(vertical, horizontal)

Base Case: dp[i][i] = 0

Final Subproblem: dp[n][m]
*/