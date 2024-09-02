#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

bool f(vector<int> &arr, int i, int sum) {
	if(i == arr.size()) {
		if(sum == 0) return true;
		return false;
	}
	bool plus = f(arr, i+1, sum + arr[i]);
	bool minus = f(arr, i+1, sum - arr[i]);
	return plus || minus;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		vector<int> arr(a+b);
		for(int i = 0; i < a; i++) arr[i] = 1;
		for(int i = 0; i < b; i++) arr[i+a] = 2;
		if(f(arr, 0, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}