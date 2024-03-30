#include <iostream>
#include <string>
using namespace std;

void file_i_o() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        int ans = -1;
        for (int i = 0; i < 6; i++) {
            if (x.find(s) != string::npos) {
                ans = i;
                break;
            }
            x += x;
        }
        cout << ans << "\n";
    }
}

int main() {
    file_i_o();
    solve();
    return 0;
}