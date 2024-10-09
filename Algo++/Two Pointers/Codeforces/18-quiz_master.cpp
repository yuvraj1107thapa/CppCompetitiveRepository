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
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for(auto &i: a) cin >> i;
		int ans = INF;
	
		int maxi = *max_element(a.begin(), a.end());
		vector<vector<int>> vi(maxi+1);
		for(int i = 1; i <= m; i++) {
			for(int j = i; j <= maxi; j+=i) {
				vi[j].push_back(i);
			}
		}
		
		vector<pair<int,int>> v; // {student, topic}
		for(int i = 0; i < n; i++) {
			for(auto j: vi[a[i]]) {
				if(j <= m) v.push_back({a[i], j});
			}
		}
		sort(v.begin(), v.end());
		
		int distinct = m;
		map<int, int> freq;
		int i = 0, j = 0;
		n = v.size();
		
		while(j < n) {
			int topic = v[j].second;
			freq[topic]++;
			
			while(i <= j && freq.size() >= distinct) {
				ans = min(ans, v[j].first - v[i].first);
				int t = v[i].second;
				freq[t]--;
				if(freq[t] == 0) {
					freq.erase(t);
				}
				i++;
			}
			j++;
		}
		
		cout << (ans == INF ? -1 : ans) << endl;
	}
}