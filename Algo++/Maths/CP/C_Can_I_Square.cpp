#include<bits/stdc++.h>
using namespace std;

void file_i_o() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

bool perfectSquare(long long n) {
    bool flag = false;
    long long i = sqrt(n);
    if(i*i == n) {
        flag = true;
    }
    return flag;
}

void solve() {
    int t;
    cin >> t;
    while(t--) {
    	long long n;
        cin >> n;
        vector<long long> v(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        if(perfectSquare(sum)) {
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