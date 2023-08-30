#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n), ans;
        int count = 1;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        ans.push_back(v[0]);
        for (int i = 1; i < n; i++) {
            if (v[i] >= v[i - 1]) {
                ans.push_back(v[i]);
                count++;
            } else {
                ans.push_back(v[i]);
                ans.push_back(v[i]);
                count += 2;
            }
        }
        cout << count << endl;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
