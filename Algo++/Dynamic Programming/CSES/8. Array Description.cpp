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
	
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	vector<vector<ll>> dp(n+1, vector<ll> (m+1, 0));
	if(arr[0] == 0) {
		for(int i = 1; i <= m; i++) {
			dp[0][i] = 1;
		}
	}
	else if(arr[0] != 0) {
		dp[0][arr[0]] = 1;
	}
	
	for(int i = 1; i < n; i++) {
		if(arr[i] == 0) {
			for(int j = 1; j <= m; j++) {
				if(j == 1) {
					dp[i][j] = (dp[i-1][j]+dp[i-1][j+1]) % mod;
				}
				else if(j == m) {
					dp[i][j] = (dp[i-1][j]+dp[i-1][j-1]) % mod;
				}
				else {
					dp[i][j] = (dp[i-1][j]+dp[i-1][j+1]+dp[i-1][j-1]) % mod;
				}
			}
		} 
		else if(arr[i] != 0) {
			int j = arr[i];
			if(arr[i] == 1) {
				dp[i][j] = (dp[i-1][j]+dp[i-1][j+1]) % mod;
			} 
			else if(arr[i] == m) {
				dp[i][j] = (dp[i-1][j]+dp[i-1][j-1]) % mod;
			}
			else {
				dp[i][j] = (dp[i-1][j]+dp[i-1][j+1]+dp[i-1][j-1]) % mod;
			}
		}
	}
	if(arr[n-1] != 0) {
		cout << dp[n-1][arr[n-1]];
	}
	else if(arr[n-1] == 0) {
		ll sum = 0;
		for(int i = 1; i <= m; i++) {
			sum = (sum + dp[n-1][i]) % mod;
		}
		cout << sum;
	}
		
	#ifndef ONLINE_JUDGE 
	  // clock_t end = clock();
	  // cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}