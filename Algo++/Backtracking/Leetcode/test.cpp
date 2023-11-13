#include <bits/stdc++.h>
using namespace std;
void dfs(vector<string>& ans, vector<string>& letters, string st, string temp){
	if(st.size()==0){
		ans.push_back(temp);
		return;
	}
	char ch=st[0];
	string letter=letters[ch-'0'];
	string ros=st.substr(1);
	for(auto i: letter){
		temp+=i;
		dfs(ans, letters, ros, temp);
		temp.pop_back();
	}
}

int  main(){
	vector<string> letters={"", "", "abc", "def", "ghi", "jkl", "mnop", "qrs", "tuv", "wxyz"};
	string st="67";
	vector<string> ans;
	dfs(ans, letters, st, "");
	for(auto i: ans){
		cout << i << endl;
	}
	return 0;
}
