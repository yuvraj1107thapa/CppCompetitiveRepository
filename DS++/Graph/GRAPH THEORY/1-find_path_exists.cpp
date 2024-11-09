#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

/*
This is not actual graph problem tho. It's grid. But yeah it's so generic, can have many usecases maybe graph too
To generalize this type of problems, Graphs used.
*/

int height, width;
bool visited[1000][1000];
bool blocked[1000][1000];

bool valid(int x, int y) {
	// check if point is outside grid or visited or blocked
	if(x < 0 || y < 0 || x >= height || y >= width || visited[x][y] || blocked[x][y]) {
		return false;
	}
	return true;
}

bool find_path(int x, int y, int ex, int ey) { // x,y to ex,ey
	if(!valid(x, y)) {
		return false;
	}
	visited[x][y] = 1;
	if(x == ex && y == ey) { // already found
		return true;
	}
	bool found = false;
	if(find_path(x+1, y, ex, ey)) found = true;
	if(find_path(x, y+1, ex, ey)) found = true;
	if(find_path(x-1, y, ex, ey)) found = true;
	if(find_path(x, y-1, ex, ey)) found = true;
	return found;
}


signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		
	}
}

// find_path(x, y, ex, ey) => return true if found else false