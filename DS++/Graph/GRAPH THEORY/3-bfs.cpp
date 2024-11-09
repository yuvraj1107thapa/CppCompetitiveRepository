#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

vector<int> adj[10000]; // adj[x] -> all vertices which have an edge with x
bool visited[10000];
int dist[10000]; // dist[x] store the distance from s to x for all x

void bfs(int s) {
	queue<int> q;
	for(int i = 1; i < 10000; i++) {
		dist[i] = INF; // initially all distance from s to x is infinite
	}
	q.push(s);
	dist[s] = 0;
	visited[s] = true;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		for(int adjacent_vertex: adj[cur]) {
			if(visited[adjacent_vertex]) {
				continue;
			}
			q.push(adjacent_vertex);
			visited[adjacent_vertex] = true;
			dist[adjacent_vertex] = dist[cur] + 1; // important
		}
	}	
	// if there is no path from s to x dist[x] will store infinity
	// else dist[x] will store shortest path from s to x
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		
	}
}