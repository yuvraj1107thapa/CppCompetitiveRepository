#include<bits/stdc++.h>
using namespace std;
#define ll 				;long long int
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
	// #ifndef ONLINE_JUDGE
	//     freopen("input.txt", "r", stdin);
	//     freopen("output.txt", "w", stdout);
	// #endif
}

/*
int dp[5005][5005][2];

ll td(vector<int> x, int i, int j, bool turn) { // check if P1 can win the game or not
    if (i > j) return 0LL;
    if (dp[i][j][turn] != -1) return dp[i][j][turn];  
    ll ans = 0;
    if (turn == false) {  // Player 1 turn -> maximize the overall score
        ans = max(x[i] + td(x, i + 1, j, true), x[j] + td(x, i, j - 1, true));
    } else { // Player 2 turn -> minimize the overall score        
    	ans = min(td(x, i + 1, j, false) - x[i], td(x, i, j - 1, false) - x[j]);
    }
    return dp[i][j][turn] = ans; // Store the result in the memoization table 
}
*/

int main(int argc, char const *argv[]) {
	// clock_t begin = clock();
	file_i_o(); 
	// Write your code here....
	
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	// memset(dp, -1, sizeof (dp));
	// ll dp[5005][5005][2];
	
	/*
	vector<vector<long long int>> dp(n, vector<long long int> (n, 0));
	for(int len = 1; len <= n; len++) {
		for(int i = 0; i+len <= n; i++) { // starting point
			int j = i+len-1// ending point
			ll a, b, c;
			a = (i+2 <= j) ? dp[i+2][j] : 0;
			b = (i+1 <= j-1) ? dp[i+1][j-1] : 0;
			c = (i <= j-2) ? dp[i][j-2] : 0;
			dp[i][j] = max(x[i]+min(a, b), x[j]+min(b, c));
		}
	}
	cout << dp[0][n-1];
	*/


	/*
	State: dp[i][j] max score a player can score for the subarray from i to j
	Transition: dp[i][j] =  max(pick i, pick j)
							pick i = x[i] + (sum[i+1][j] - dp[i+1][j])
							pick j = x[j] + (sum[i][j-1] - dp[i][j-1])
	Base Case: dp[i][i] = x[i]
	Final Subproblem: dp[0][n-1]
	Time and Space Complexity: n^2
	*/

	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, inf));
	vector<vector<long long>> sum(n + 1, vector<long long>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		ll curr = 0;
		for (int j = i; j < n; j++) {
			curr += x[j];
			sum[i][j] = curr;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if(i > j) {
				continue;
			}
			else if (i == j) {
				dp[i][j] = x[i];
			}
			else {
				dp[i][j] = max(x[i] + (sum[i + 1][j] - dp[i + 1][j]), x[j] + (sum[i][j - 1] - dp[i][j - 1]));
			}
		}
	}
	cout << dp[0][n - 1];
	// #ifndef ONLINE_JUDGE
	// clock_t end = clock();
	// cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	// #endif
	return 0;
}

/*
Observation:
P1 can choose st or end element of arr
if p1 choose st then arr remain i+1...j
if p1 choose end then arr remain i...j-1


Idea:
s1+s2 = total_sum
s1-s2 = |s1-s2|
2*s1 = 
s1 =

Maximize x-y

x+y = c (sum of all elements)
y = c-x

putting y value in x-y
x-(c-x)
Bracket open
2*x - (c)    -> x (this whole value depends on x, inc/dec with x)
So, maximize X or minimize Y



We have to maximize or minimize

Now p2 turn

State:

dp[l][r][p] = segment remaining l..r inclusive (what would be the ans. if pth player turn)
p = 0, first
p = 1, second
-> store resulting value of x

Final ans: 2*x - sum
- 2*(dp[l][r][0]) - C


Transition:
f(i,j) = max(min(a[i]+f(i+2,j) , a[i]+f(i+1,j-1)), min(a[j]+f(i,j-2) , a[j]+f(i+1,j-1)));

Base Case:
dp[i][i][0] = a[i]
dp[i][i][1] = 0

Final Subproblem: 2*(dp[0][n-1][0]) - (sum)


best move/choice acc. to whole global search space 


Transition:
pick l or pick r
dp[l][r][0] = max(a[l] + dp[l+1][r][1], a[r] + dp[l][r-1][1])
dp[l][r][1] = min(dp[l+1][r][0], dp[l][r-1][0]) (not concerning about y)


Order of evalation:
(r-l) decrease -> want increasing order of r-l

*/