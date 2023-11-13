#include <bits/stdc++.h>
using namespace std;

int isValid(string s){

	stack<char> st;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			if(!st.empty() && st.top()=='('){
				st.pop();
			}
			else{
				st.push(s[i]);
			}
		}
	}

	return st.size();
}

void dfs(unordered_set<string>& m, vector<string>& ans, string s, int minRemoval){

	if(minRemoval==0){
		if(isValid(s)==0){
			ans.push_back(s);
		}
		return;
	}

	for(int i=0; i<s.size(); i++){
		if(s[i]>='a' && s[i]<='z') continue;
		string left=s.substr(0, i);
		string right=s.substr(i+1);
		string temp=left+right;
		if(m.count(temp)==0){
			m.insert(temp);
			dfs(m, ans, temp, minRemoval-1);
		}
	}
}

vector<string> removeInvalidParentheses(string s){

	unordered_set<string> m;
	vector<string> ans;
	int minRemoval=isValid(s);
	dfs(m, ans, s, minRemoval);

	return ans;
}

int main(){
		
	string s="(()()())))";
	vector<string> ans=removeInvalidParentheses(s);
	for(auto i: ans){
		cout << i << endl;
	}

	return 0;
}