#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

vector<int> adj[10000]; // adj[x] -> all vertices which have an edge with x;
bool visited[10000];

bool find_path(int curr, int destination) {
	if(curr == destination) {
		return true;
	}
	visited[curr] = true;
	bool found = false;
	for(int adjacent_vertex: adj[curr]) {
		if(visited[adjacent_vertex]) {
			continue;
		}
		if(find_path(adjacent_vertex, destination)) {
			found = true;
		}
	}
	return found;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		
	}
}