#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, mex = -1;
        cin >> n >> k;
        k %= (n + 1);
        vector<int> v(n + 1);
        vector<int> v2(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            v2[v[i]]++;
        }
        for (int i = 0; i <= n; i++) {
            if (v2[i] == 0) {
                mex = i;
                break;
            }
        }
        v[0] = mex;
        for (int i = 0; i <= n; i++) {
            if (n < (i + k)) v2[(i + k) % (n + 1)] = v[i];
            else v2[i + k] = v[i];
        }
        for (int i = 1; i <= n; i++) {
            cout << v2[i] << " ";
        }
        cout << endl;
    }
    return 0;
}