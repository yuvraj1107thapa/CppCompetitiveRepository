#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int smallestDivisor(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return i;
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        bool flag = true;
        if (l == r && (l == 1 || isPrime(l))) flag = false;
        else if ((l == 1) && (r == 2 || r == 3) || (l == 2 && r == 3)) flag = false;
        if (not flag) cout << -1;
        else {
            if (l == r) {
                if (l % 2 == 0) {
                    cout << l / 2 << " " << l / 2;
                } else {
                    int x = smallestDivisor(l);
                    cout << x << " " << l - x;
                }
            } else {
                if (l % 2 != 0 && l != 1) {
                    l++;
                } else if (l == 1) {
                    l += 3;
                } else if (l == 2) {
                    l += 2;
                }
                cout << l / 2 << " " << l / 2;
            }
        }
        cout << endl;
    }
    return 0;
}
