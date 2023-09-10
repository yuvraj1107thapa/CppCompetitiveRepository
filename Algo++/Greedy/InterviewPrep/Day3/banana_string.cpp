// Problem Link - https://www.codechef.com/PLIT2020/problems/BANSTR
/* By Yuvraj Thapa */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define nl				"\n"
#define pb 				push_back
#define eb				emplace_back
#define vi              std::vector<ll>
#define vs				std::vector<std::string>
#define pii             std::pair<ll,ll>
#define ump				std::unordered_map
#define mp 				std::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;	
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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int t;
    std::cin>>t;
    while(t--) {
        int n, p;
        std::cin>>n>>p;
        std::string str;
        std::cin>>str;
        std::vector<std::pair<char, bool> > v;
        std::vector<int> b_s, a_s;
        for(int i = 0; i < str.size(); i++) {
            v.pb({str[i], false});
            if(str[i] == 'a') a_s.pb(i);
            else b_s.pb(i);
        }
        while(a_s.size() > 0 and b_s.size() > 0 and p > 0 and a_s.back() > b_s[0]) {
            std::swap(v[a_s.back()], v[b_s[0]]);
            v[a_s.back()].ss = v[b_s[0]].ss = true;
            a_s.pop_back();
            b_s.erase(b_s.begin());
            p--;
        }
        for(int i = 0; i < n; i++) {
            if(v[i].ff == 'a') continue;
            else {
                if(v[i].ss == true and p >= 1) {
                    p-=1;
                    v[i].ff = 'a';
                } else if(p >= 2) {
                    p -= 2;
                    v[i].ff = 'a';
                }
            }
        }
        for(int i = 0 ; i < n; i++) {
            std::cout<<v[i].ff;
        }
        std::cout<<"\n";
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}