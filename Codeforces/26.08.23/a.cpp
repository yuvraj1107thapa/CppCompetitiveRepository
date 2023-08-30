#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int x, y, n;
		cin >> x >> y >> n;
		vector<int> arr;
		int count = 1;
		for(int i = 0; i < n; i++) {
			arr.push_back(y);
			y -= count;
			count++; 
		}
		if(arr[arr.size()-1] < x) {
			cout<< -1 << endl;
		} else {
			cout << x << " ";
			for(int i = arr.size()-2; i>= 0; i--) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}	
	return 0;
}