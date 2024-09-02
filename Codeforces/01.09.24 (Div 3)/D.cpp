#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

const int N = 1e6;
int parent[N], siz[N];

int findParent(int i) {
    if(parent[parent[i]]!=parent[i])
        parent[i]=findParent(parent[i]);
    return parent[i];
}
void unionNodes(int a,int b) {
    int parent_a=findParent(a),parent_b=findParent(b);
    if(parent_a==parent_b)
        return;
    if(siz[parent_a]>=siz[parent_b]){
        swap(parent_a,parent_b);
    }
    siz[parent_b]+=siz[parent_a];
    parent[parent_a]=parent_b;
    return;
}
void cleardsu(int n){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        siz[i]=1;
    }
}


signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for(auto &i: arr) cin >> i;
		string s;
		cin >> s;
		
		
	}
}