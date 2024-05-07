#include<bits/stdc++.h>
using namespace std;

void file_i_o() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        int count = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 0) {
                count++;
            }
            else {
                ans = max(ans, count);
                count = 0;
            }
        }
        cout << max(ans, count) << endl;
    }
}

int main() {
	file_i_o(); 
	solve();
	return 0;
}