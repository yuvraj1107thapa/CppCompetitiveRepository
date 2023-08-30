#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        int count = 0;
        string str = "vika";
        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = v[j][i];
                if (ch == str[idx]) {
                    idx++;
                    count++;
                    break;
                }
            }
            if (count == 4) break;
        }

        if (count == 4) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;   
}
