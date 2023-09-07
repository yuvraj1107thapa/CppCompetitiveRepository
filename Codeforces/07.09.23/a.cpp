#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < b) {
            swap(a, b); 
        }
        int ans = 0;
        while (a != b) {
            if ((a - b) > 2*c) {
                a = a - c;
                b = b + c;
                ans++;
            } else {
                a = b;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
