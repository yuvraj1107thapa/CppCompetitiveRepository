#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

long long sum_of_n(int n) {
    return n * (n + 1) / 2;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int tc; cin >> tc;
    while (tc--) {
        long long n, k;
        cin >> n >> k;
        int total_sum = n*k + sum_of_n(n - 1);

        int l = 1, r = n;
        int ans = INF;
        
        while(l <= r) {
            int mid = (l+r) / 2;
            
            int left_sum = mid*k + sum_of_n(mid - 1);
            int right_sum = total_sum - left_sum;
            int diff = abs(left_sum - right_sum);
            ans = min(ans, diff);
            
            if (left_sum < right_sum) {
                l = mid +1;
            } 
            else r = mid - 1;
        }
        
        cout << ans << endl;
    }
}