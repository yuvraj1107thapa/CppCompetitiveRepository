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
		int N, M; cin >> N >> M;
		vector<int> limit(100, 0);
		for(int i = 0; i < N; i++) {
			int miles, speed; cin >> miles >> speed;
			for(int j = i; j < miles; j++) limit[j] = speed;			
		}
		vector<int> bessie(100, 0);
		for(int i = 0; i < M; i++) {
			int miles, speed; cin >> miles >> speed;
			for(int j = i; j < miles; j++) bessie[j] = speed;			
		}
	
		int maxi = INT_MIN;
		for(int i = 0; i < 100; i++) {
			maxi = max(maxi, bessie[i]-limit[i]);
		}
		
		cout << maxi << endl;
	}
}