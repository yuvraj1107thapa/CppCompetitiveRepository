#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        if (n % 2 == 0) {
	        vector<int> even_freq(26, 0), odd_freq(26, 0);
	        for(int i = 0; i < n; i++) {
	            if(i % 2 == 0) {
	                even_freq[s[i]-'a']++;
	            }
	            else {
	                odd_freq[s[i]-'a']++;
	            }
	        }
	        
	        int max_even = 0, max_odd = 0;
	        for(int c = 0; c < 26; c++){
	            max_even = max(max_even, even_freq[c]);
	            max_odd = max(max_odd, odd_freq[c]);
	        }
	        
	        cout << (n - (max_even+max_odd)) << endl;
	    }
	    else {
	        vector<vector<int>> prefix_even(26, vector<int>(n+1, 0));
	        vector<vector<int>> prefix_odd(26, vector<int>(n+1, 0));
	        vector<vector<int>> suffix_even(26, vector<int>(n+2, 0));
	        vector<vector<int>> suffix_odd(26, vector<int>(n+2, 0));

	        for(int i = 0; i < n; i++){
	            for(int c = 0; c < 26; c++){
	                prefix_even[c][i+1] = prefix_even[c][i];
	                prefix_odd[c][i+1] = prefix_odd[c][i];
	            }
	            if(i % 2 == 0) {
	                prefix_even[s[i]-'a'][i+1]++;
	            }
	            else {
	                prefix_odd[s[i]-'a'][i+1]++;
	            }
	        }

	        for(int i = n-1; i >=0; i--){
	            for(int c = 0; c < 26; c++){
	                suffix_even[c][i+1] = suffix_even[c][i+2];
	                suffix_odd[c][i+1] = suffix_odd[c][i+2];
	            }
	            if(i % 2 == 0){
	                suffix_even[s[i]-'a'][i+1]++;
	            }
	            else{
	                suffix_odd[s[i]-'a'][i+1]++;
	            }
	        }

	        int max_t = 0;

	        for(int i = 0; i < n; i++){
	            int curr_max_even = 0, curr_max_odd = 0;
	            for(int c = 0; c < 26; c++){
	                int count_even = prefix_even[c][i] + suffix_odd[c][i+2];
	                int count_odd = prefix_odd[c][i] + suffix_even[c][i+2];
	                curr_max_even = max(curr_max_even, count_even);
	                curr_max_odd = max(curr_max_odd, count_odd);
	            }
	            max_t = max(max_t, curr_max_even + curr_max_odd);
	        }
	        
	        cout <<  1 + ((n-1) - max_t) << endl;
	    }
  	}
}
