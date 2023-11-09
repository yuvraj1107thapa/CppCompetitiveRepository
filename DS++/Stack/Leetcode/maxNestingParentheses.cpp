#include <bits/stdc++.h>
using namespace std;

int maxNestingParentheses(string s){

	stack<char> st;
	int ans=0;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='('){
			st.push('(');
			int currentSize=st.size();
			ans=max(ans, currentSize);
		}
		else if(s[i]==')'){
			st.pop();
		}
	}

	return ans;
}

int main(){
	
	string str="(1+(2*3)+((3)/1))+1";
	cout << maxNestingParentheses(str) << endl;

	return 0;
}