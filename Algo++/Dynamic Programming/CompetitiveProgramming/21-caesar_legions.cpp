#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e8;
const int INF = LLONG_MAX >> 1;

const int N = 101, K = 11;
int dp[N][N][K][K];

int f(int F, int H, int CF, int CH, int k1, int k2) {
	if(F == 0 && H == 0) {
		return 1;
	}
	
	if(dp[F][H][CF][CH] != -1) return dp[F][H][CF][CH];
	
	int c = 0;
	
	if(F > 0 && CF < k1) {
		c = (c + f(F-1, H, CF+1, 0, k1, k2)) % MOD;
	}
	if(H > 0 && CH < k2) {
		c = (c + f(F, H-1, 0, CH+1, k1, k2)) % MOD;
	}
	
	return dp[F][H][CF][CH] = c;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; 
	// cin >> tc;
	while (tc--) {
		int n1, n2, k1, k2;
		cin >> n1 >> n2 >> k1 >> k2;
		
		memset(dp, -1, sizeof dp);
		cout << f(n1, n2, 0, 0, k1, k2) << endl;
	}
}