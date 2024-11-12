// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// void file_i_o() {
//     ios_base::sync_with_stdio(0); 
//     cin.tie(0); 
//     cout.tie(0);
// }

// void solve() {
//     int t;
//     cin >> t;
//     while(t--) {
//         ll n;
//         cin >> n;
//         vector<ll> a;
//         for (int i = 0; i < n; ++i) {
//             ll x;
//             cin >> x;
//             if (i && a.back() > x) {
//                 a.push_back(1);
//             }
//             a.push_back(x);
//         }
//         cout << a.size() << "\n";
//         for (ll el : a)
//             cout << el << " ";
//         cout << "\n";
//     }
// }

// int main() {
// 	file_i_o(); 
// 	solve();
// 	return 0;
// }

#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (i && a.back() > x) {
                a.push_back(1);
            }
            a.push_back(x);
        }
        cout << a.size() << "\n";
        for (int el : a)
            cout << el << " ";
        cout << "\n";
    }
    return 0;
}