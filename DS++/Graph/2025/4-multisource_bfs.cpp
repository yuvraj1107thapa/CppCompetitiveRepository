#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


//TODO:	
vector<int> adj[10000]; // adj[x] -> all vertices which have an edge with x
bool visited[10000];
vector<pair<int, int>> dist(10000); // dist[x] store the distance from s to x for all x

void bfs(int s) {
	queue<pair<int, int>> q; // {current, starting vertex}
	for(int i = 1; i < 10000; i++) {
		dist[i].second = INF; // initially all distance from s to x is infinite
	}
	int x = 0;
	q.push({x, x}); // whatever the special node is who connect all special vertex, push that node here
	dist[s].first = 0;
	dist[s].second = 0;
 	visited[s] = true;
	while(!q.empty()) {
		int cur = q.front().first;
		int sf = q.front().second;
		q.pop();
		for(int adjacent_vertex: adj[cur]) {
			if(visited[adjacent_vertex]) {
				continue;
			}
			q.push({adjacent_vertex, sf});
			visited[adjacent_vertex] = true;
			dist[adjacent_vertex].first = dist[cur].first + 1; // important
			dist[adjacent_vertex].second = sf; // important: started from (Hospital)
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