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
        string s;
        cin >> s;
        vector<int> freq(30, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        int maxi = 0;
        for (int i = 0; i < 26; i++) {
            maxi = max(maxi, freq[i]);
        }
        if(maxi > (n/2)) {
            cout << n - ((n-maxi) * 2) << "\n";
        } else {
            cout << n % 2 << "\n";
        }
    }
}

int main() {
	file_i_o(); 
	solve();
	return 0;
}