#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        if (str == "()") {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        string a = string(str.size(), '(') + string(str.size(), ')');
        string b = "";
        for (int i = 0; i < str.length(); i++) {
            b += "()";
        }
        if (b.find(str) != string::npos) {
            cout << a << endl;
        } else {
            cout << b << endl;
        }
    }
    return 0;
}
