#include <bits/stdc++.h>
using namespace std;

#define int long long

void file_i_o() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        vector<int> count(2, 0);
        for(int i = 0; i < n-1; i++) {
            if(str[i] == str[i+1] and str[i]=='0') continue;
            count[str[i]-'0']++;
        }
        str[n-1]=='0' ? count[0]++ : count[1]++;
        cout << (count[1] > count[0] ? "YES" : "NO") << endl;
    }
}

signed main() {
    file_i_o();
    solve();
    return 0;
}
