#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int maxSubarraySum(int l, int r, vector<int>& arr) {
	int maxi = -INF, sum = 0;
	for(int i = l; i <= r; i++) {
		sum += arr[i];
		maxi = max(sum, maxi);
		if(sum < 0) sum = 0;
	}
	return maxi;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<int> arr(n);
		for(auto &i: arr) cin >> i;
		
		int Yasser = accumulate(arr.begin(), arr.end(), 0LL);
		int Adel = max(maxSubarraySum(0, n-2, arr), maxSubarraySum(1, n-1, arr));
		if(Yasser > Adel) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}