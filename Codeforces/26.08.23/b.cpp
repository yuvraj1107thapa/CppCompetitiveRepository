#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        if (k % 2 == 0) {
            sort(str.begin(), str.end());
            cout << str << endl;
        } else {
            unordered_map<char, int> m[2]; 
            for (int i = 0; i < n; i++) {
                m[i % 2][str[i]]++;
            }
            string ans = "";
            for (int i = 0; i < n; i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (m[i % 2][ch] > 0) {
                        m[i % 2][ch]--;
                        ans += ch;
                        break;
                    }
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
