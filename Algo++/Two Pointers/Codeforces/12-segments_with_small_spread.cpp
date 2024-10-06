#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define ll long long

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; 
// find_by_order, order_of_key

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; //cin >> tc;
	while (tc--) {
		long long n, k;
		cin >> n >> k;
		vector<long long> a(n);
		for(auto& i: a) 
			cin >> i;
		long long c = 0;
		pbds A;
		int i = 0, j = 0;
		while(j < n) {
			A.insert({a[j], j});
			while(i < j && ((*A.find_by_order(A.size()-1)).first - (*A.find_by_order(0)).first) > k) {
				A.erase({a[i], i});
				i++;
			}
			c += j-i+1;
			j++;
		}
		cout << c << endl;
	}
}