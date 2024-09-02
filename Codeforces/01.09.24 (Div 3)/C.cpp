#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

const int MAXN = 44721;

vector<int> prefixSum(MAXN + 1, 0);

void precompute() {
    int current = 0;
    for (int i = 1; i <= MAXN; i++) {
        current += i;
        prefixSum[i] = current;
    }
}

int solve(int l, int r) {
    int diff = r - l;
    int L = 0, R = MAXN;
    while (L <= R) {
        int mid = (L+R) / 2;
        if (prefixSum[mid] <= diff) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    return R;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    precompute();
    
    int t; cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r) + 1 << endl;
    }
    
    return 0;
}