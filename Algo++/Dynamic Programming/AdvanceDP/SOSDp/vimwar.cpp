// Problem Link - https://www.hackerrank.com/challenges/vim-war/problem
/* By Yuvraj Thapa */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define ll                 long long int
#define ld                long double
#define mod             1000000007
#define inf             1e18
#define nl                "\n"
#define pb                 push_back
#define eb                emplace_back
#define vi              std::vector<ll>
#define vs                std::vector<std::string>
#define pii             std::pair<ll,ll>
#define ump                std::unordered_map
#define mp                 std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n)             n.begin(),n.end()
#define ff                 first
#define ss                 second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n)         __builtin_popcount(n)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)     for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)     { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;    
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(std::string str,char ch) {std::istringstream var((str)); vs v; std::string t; while(std::getline((var), t, (ch))) {v.pb(t);} return v;}


void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void file_i_o()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
}

ll cnt[2000005];
ll p2[2000005];
ll dp[2000005][21];
int n, m;
ll str_num(std::string &s) {
    ll num = 0;
    for(ll i =0; i < s.size(); i++) {
        num = (num*2 + (s[i] - '0'));
    }
    return num;
}
ll f(ll mask, ll pos) {
    if(pos == -1) {
        return cnt[mask];
    }
    if(dp[mask][pos] != -1) return dp[mask][pos];
    ll ans = 0;
    if((1<<pos)&mask) {
        ans = (ans + f(mask^(1<<pos), pos-1));
        ans = (ans + f(mask, pos-1));
    } else {
        ans = (ans + f(mask, pos-1));
    }
    return dp[mask][pos] = ans;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    std::memset(dp, -1, sizeof dp);
    p2[0] = 1;
    for(ll i = 1; i < 100005; i++) {
        p2[i] = (p2[i-1]*2)%mod;
    }
    //log(p2[3]);
    std::cin>>n >>m;
    std::string ss;
    for(ll i = 0;i < n; i++) {
        std::cin>>ss;
        //log(str_num(ss));
        cnt[str_num(ss)]++;
    }
    ll reqmask;
    std::cin>>ss;
    reqmask = str_num(ss);
    //log(reqmask);
    ll ans = 0;
    for(ll i = 0; i < (1 << m); i++) {
        if((i&reqmask) != i) continue;
        if((__builtin_popcount(i) - __builtin_popcount(reqmask))%2) {
            ans = (ans - p2[f(i, m-1)] + mod)%mod;
        } else {
            ans = (ans + p2[f(i, m-1)])%mod;
        }
        //log(ans);
    }
    
    if(reqmask == 0) {
        ans--;
    }
    std::cout<<ans<<"\n";


    // #ifndef ONLINE_JUDGE 
    //   clock_t end = clock();
    //   std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    // #endif 
    return 0;
}