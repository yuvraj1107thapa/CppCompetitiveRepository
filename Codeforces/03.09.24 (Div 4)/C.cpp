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
        long long x, y, k;
        cin >> x >> y >> k;
        
        long long jumps = 0;
        
        int jumps_x = (x + k - 1) / k;
        int jumps_y = (y + k - 1) / k;
        jumps = max(jumps_x*2 - 1, jumps_y*2);
        
        cout << jumps << endl;
    }
}