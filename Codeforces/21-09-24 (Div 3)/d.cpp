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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &i: arr) cin >> i;
            
        int sum = accumulate(arr.begin(), arr.end(), 0LL);
 
        if(n == 1) {
            cout << -1 << endl;
            continue;
        }
        if(n == 2) {
            cout << -1 << endl;
            continue;
        }
        
        sort(arr.begin(), arr.end());
 
        int l = 0, r = 1e18;
        int ans = -1;
 
        while (l <= r) {
            int mid = (l + r) / 2;

            double avg = (double)(sum + mid) / n;
            double half_avg = avg / 2.0;

            int unhappy = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] < half_avg) {
                    unhappy++;
                }
            }

            if (unhappy > n / 2) {
                ans = mid; 
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << (ans < 0 ? 0 : ans) << endl;
    }
}