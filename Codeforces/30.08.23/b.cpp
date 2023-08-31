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
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[v[i]] = i;
        }
        int operations = 0;
        for (auto i : v) {
            if (i == 1) continue;
            int current_pos = mp[i];
            int correct_pos = mp[i - 1];
            if (current_pos < correct_pos) {
                operations++;
            }
        }
        cout << operations << endl;
    }
    return 0;
}
