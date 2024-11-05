#include<bits/stdc++.h>
using namespace std;

void file_i_o() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

void solve() {
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, t;
        cin >> n >> t;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int ans = 0;
        long long sum = 0;
        int i = 0, j = 0;
        while(j < n) {
            sum+=v[j];
            while(i <= j and sum > t) {
                sum-=v[i];
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        cout << ans << endl;
        
    }
}

int main() {
	file_i_o(); 
	solve();
	return 0;
}

/*
Find a longest length subarray whose sum <= t
*/