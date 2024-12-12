#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007 
#define inf             1e18 
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

/*--------------------------------------------------------------------------------------------------------------*/


const int N = 1005;

int n, m;
int x, y;
string s[N];
bool vis[N][N];

bool valid(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) {
        return 0;
    }
    if(s[x][y] == '#') {
        return 0;
    }
    return 1;
}

vector<char> cur;

// graph moves
char moves[4] = {'L','U','R','D'};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

char parent[N][N];
pii cell[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if(s[i][j] == 'A') {
                x = i;
                y = j;
            }
        }
    }
    
    queue<pii> q;
    q.push({x,y});
    
    bool found = 0;
    vis[x][y] = 1;
    int xB, yB;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(s[x][y] == 'B') {
            found = 1;
            xB = x, xB = y;
        }
        for(int i = 0; i < 4; i++) {
            // x+dx[i], y+dy[i]
            int X = x+dx[i], Y = y+dy[i];
            if(valid(X,Y)) {
                vis[X][Y] = 1;
                q.push({X,Y});
                parent[X][Y] = moves[i];
                cell[X][Y] = {x,y};
            }
        }
    }
    
    if(!found) {
        cout << "NO" << endl;
        return;
    }
    vector<int> cur;
    // traceback from B
    while(x != xB || y != yB) {
        cur.pb(parent[xB][yB]);
        pii tmp = cell[xB][yB];
        xB = tmp.ff;
        yB = tmp.ss;
    }
    
    reverse(all(cur));
    cout << "YES\n" << cur.size() << endl;
    for(char c: cur) {
        cout << c;
    }
}


int main(int argc, char const *argv[]) {
	file_i_o(); 
	// Write your code here....
	solve();
	return 0;
}