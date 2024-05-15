#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007 // 10^9+7
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
	
	int h, w;
	cin >> h >> w;
	
	/*
	vector<vector<ll>> dp(h+1, vector<ll> (w+1, inf));
	
	for(int i = 1; i <= h; i++) { // height
		for(int j = 1; j <= w; j++) { // width
			// no cuts req.
			if(i == j) {
				dp[i][j] = 0;
				continue;
			}
			// horizontal cut
			for(int k = 1; k <= i-1; k++) {
				dp[i][j] = min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
			}
			// vertical cut
			for(int k = 1; k <= j-1; k++) {
				dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
			}
		}
	}
	
	cout << dp[h][w] << endl;
	*/

	vector<vector<int>> dp(h + 1, vector<int>(w + 1, inf));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if(i == j) {
				dp[i][j] = 0;
			} else {
				// horizontal cut
				for (int k = 1; k <= i-1; k++) {
					dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
				}
				// horizontal cut
				for (int k = 1; k <= j-1; k++) {
					dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i ][j-k]);
				}
			}
		}
	}
	cout << dp[h-1][w-1];

#ifndef ONLINE_JUDGE 
	  // clock_t end = clock();
	  // cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

/*
Observation:

Choice = Cut or not cut vertically + Cut or not cut horinzontally


State: dp[i][j] = min cut require to make i x j rectangle into squares
Transition: dp[i][j] = 1+min(horizontalCut, verticalCut);
			horizontalCut = problem divides into [k x j] and [m-k x j] rectangle => min(horizontal, dp[k][j]+dp[m-k][j]);
			verticalCut = problem divides into [i x k] and [i x n-k] rectangle => min(horizontal, dp[k][j]+dp[m-k][j]);
Base case: dp[i][i] = 0
Final Subproblem: dp[m][n];

*/