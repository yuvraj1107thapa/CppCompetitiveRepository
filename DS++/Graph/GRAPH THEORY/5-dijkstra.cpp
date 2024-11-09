#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

vector<pair<int, int>> adj[10000]; // weighted graph, {adj_vertex, weight}
int dist[10000]; // dist[x] stores distance from source to x
bool visited[10000];

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc = 1; //cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
	        dist[i] = INF;
	        visited[i] = false;
    	}
    	
		for(int i = 0; i < m; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			adj[x].push_back({y,w});
			adj[y].push_back({x,w});
		}
		
		for(int i = 1; i <= n; i++) {
			cout << "[" << i << "]" << "->";
			for(auto x: adj[i]) {
				cout << x.first << "->";
			}
			cout << endl;
		}
		cout << endl;
		
		int source;
		cin >> source;
		
		set<pair<int, int>> s; // {distance, vertex}, also priority queue faster than set
		s.insert({0, source});
		while(!s.empty()) {
			int curr = s.begin() -> second;
			int d = s.begin() -> first;
			
			s.erase(s.begin());
			if(visited[curr]) {
				continue;
			}
			dist[curr] = d;
			visited[curr] = true;
			for(auto adjacent_vertex: adj[curr]) {
				if(visited[adjacent_vertex.first]) {
					continue;
				}
				// distance = d + adjacent_vertex.second, vertext = adjacent_vertext.first
				s.insert({d + adjacent_vertex.second, adjacent_vertex.first});
			}
		}
		
		for(int i = 1; i <= n; i++) { // Assuming 1-based indexing for output
            if(dist[i] == INF) {
                cout << i << "---" << "INF" << endl;
            } else {
                cout << i << "---" << dist[i] << endl;
            }
        }
	}
}