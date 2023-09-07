#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> d(n);
        vector<int> s(n);
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            cin >> d[i] >> s[i];
        }
        for(int i = 0; i < n; i++) {
            int safetime = (s[i]-1)/2;
            ans = min(ans, safetime+d[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
