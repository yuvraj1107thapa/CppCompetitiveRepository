#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin >> tc;
    while(tc--) {
        int n;
        string s;
        cin >> n >> s;
        
        int side = sqrt(n);
        if(side * side != n) {
            cout << "No" << endl;
            continue;
        }
        
        if (side == 1) {
            cout << (s[0] == '1' ? "Yes" : "No") << endl;
            continue;
        }
        
        bool ok = true;
        
        for(int i = 0; i < side; i++) {
            if(s[i] != '1' || s[(side-1)*side + i] != '1') {
                ok = false;
                break;
            }
        }
        
        if(ok) {
            for(int i = 0; i < side; i++) {
                if(s[i*side] != '1' || s[i*side + side-1] != '1') {
                    ok = false;
                    break;
                }
            }
        }
        
        if(ok) {
            for(int i = 1; i < side-1; i++) {
                for(int j = 1; j < side-1; j++) {
                    if(s[i*side + j] != '0') {
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
        }
        
        cout << (ok ? "Yes" : "No") << endl;
    }
}