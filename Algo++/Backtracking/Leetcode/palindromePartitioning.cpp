#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){

	while(i<j){
		if(s[i++]!=s[j--]){
			return 0;
		}
	}
	return 1;
}

void dfs(string s, vector<vector<string>>& ans, vector<string> ds, int idx){

	if(idx==s.size()){
		ans.push_back(ds);
		return;
	}

	for(int i=idx; i<s.size(); i++){
		if(isPalindrome(s, idx, i)){
			ds.push_back(s.substr(idx, i-idx+1));
			dfs(s, ans, ds, i+1);
			ds.pop_back();
		}
	}
}

vector<vector<string>> partition(string s){

	vector<vector<string>> ans;
	vector<string> ds;
	dfs(s, ans, ds, 0);
	return ans;
}

int main(){

	string s="lalita";
	vector<vector<string>> ans;
	ans=partition(s);
	for(int i=0; i<ans.size(); i++){
		for(int j=0; j<ans[0].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
