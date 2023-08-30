#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int mini = 0, cookie_seller = 0;
	while(t--) {
		int n, m, d;
		cin >> n >> m >> d;
		unordered_map<int, int> mp;
		for(int i = 0; i < m; i++) {
			mp[i] = 1;
		}
		int time = 0;
		int cookies = 0;
		for(int i = 0; i << n; i++) {
			if(i == 0) {
				cookies++;
				time = 1;
			}
			if(mp[i] && time == d) {
				cookies++;
				time = 1;
			} else if(time == d) {
				cookies++;
				time = 1;
			} else if(mp[i]) {
				cookies++;
				time = 1;
			} 
			time++;
		}
		for(int i = 0; i < n; i++) {
			if(mp[i]) {
				int seller = mp[i];
				time = 0;
				cookies = 0;
				for(int j = 0; j < n; j++) {
					if(j == 0) {
						cookies++;
						time = 1;
					} 
					if(j == seller) {
						if(time == d) {
							cookies++;
							time = 1;
						}
					} 
					else if(time == d && mp[i] && mp[i] != seller) {
						cookies++;
						time = 1;
					}
					else if(mp[i] != seller) {
						cookies++;
						time = 1;
					} 
					else if(time ==d) {
						cookies++;
						time = 1;
					}
					time++;
				}
				if(cookies == mini) {
					cookie_seller++;
				} else if(cookies < mini) {
					cookie_seller = 1;
					mini = cookies;	
				}
			}
		}
	}
	cout << mini << " " << cookie_seller;
	return 0;
}