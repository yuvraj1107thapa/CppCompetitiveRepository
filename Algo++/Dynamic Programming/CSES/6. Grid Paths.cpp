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
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int main(int argc, char const *argv[]) {
	// clock_t begin = clock();
	file_i_o();
	// Write your code here....
	
	int n;
	cin >> n;
	// vector<vector<char>> grid(n, vector<char> (n, 0));
	// for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < n; j++) {
	// 		cin >> grid[i][j];
	// 	}
	// }
	string grid[n];
	for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
	vector<vector<int>> dp(n, vector<int> (n, 0));
	
	if(grid[n-1][n-1] == '*') {
		dp[n-1][n-1] = 0;
	} else{
		dp[n-1][n-1] = 1;
	}
	for (int i = n - 2; i >= 0; i--) {
		if(grid[n-1][i] == '*') {
			dp[n-1][i] = 0;
		} else {
			dp[n-1][i] = dp[n-1][i+1];
		}
		
		if(grid[i][n-1] == '*') {
			dp[i][n-1] = 0;
		} else {
			dp[i][n-1] = dp[i+1][n-1];
		}     	  
    }

	for(int i = n-2; i >= 0; i--) {
		for(int j = n-2; j >= 0; j--) {
			if(grid[i][j] == '*') continue;
			dp[i][j] = (dp[i+1][j]+dp[i][j+1])%mod;
		}
	}
	cout << dp[0][0];
	#ifndef ONLINE_JUDGE 
	  // clock_t end = clock();
	  // cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}