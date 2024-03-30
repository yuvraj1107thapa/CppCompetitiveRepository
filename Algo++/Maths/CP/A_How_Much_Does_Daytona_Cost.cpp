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
	while(t--){
		int n, k;
		cin >> n >> k; 
		bool flag = false;
		for(int i = 0; i < n; i++){
            int j;
            cin >> j;
			if(j == k) {
                flag = true;
            }
        }
		if(flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
	}
}

int main() {
	file_i_o(); 
	solve();
	return 0;
}