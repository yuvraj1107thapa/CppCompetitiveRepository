#include <bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string str){

	stack<int> st;

	for(int i=0; i<str.size(); i++){
		if(str[i]=='('){
			st.push(i);
		}
		else if(str[i]==')'){
			if(st.empty()){
				str[i]='.';
			}
			else{
				st.pop();
			}
		}
	}

	while(!st.empty()){
		str[st.top()]='.';
		st.pop();
	}

	string ans="";
	for(int i=0; i<str.size(); i++){
		if(str[i]!='.'){
			ans+=str[i];
		}
	}

	return ans;
}

int main(){
	
	string str="))((";
	cout << minRemoveToMakeValid(str) << endl;

	return 0;
}