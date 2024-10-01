#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        
        int leaves = n * (n + 1) * (2 * n + 1) / 6;
        if (n > k) {
            int exc_yr = n - k;
            int exc_leaves = exc_yr * (exc_yr + 1) * (2 * exc_yr + 1) / 6;
            leaves -= exc_leaves;
        }
        cout << (leaves % 2 == 0 ? "YES" : "NO") << endl;
    }
}