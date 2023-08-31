#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, a , q;
		cin >> n >> a >> q;
		string str;
		cin >> str;
		int count = a, plus = 0;
		bool flag = false;
		if(a >= n) {
			cout << "YES" << endl;
			continue;
		}
		for(int i = 0; i < str.size(); i++) {
			if(str[i] == '+') {
				count++; plus++;
			} else count--;
			if(count == n) {
				cout << "YES" << endl;
				flag = true;
				break;
			}
		}
		if(flag != true) {
			if(plus >= n-a) cout << "MAYBE" << endl;
			else cout << "NO" << endl;
		}
	}	
	return 0;
}
