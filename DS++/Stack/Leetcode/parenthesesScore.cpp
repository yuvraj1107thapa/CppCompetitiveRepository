#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string str){
	
	stack<int> st;
	for(int i=0; i<str.size(); i++){
		if(str[i]=='('){
			st.push(-1);
		}
		else{
			int val=0;
			if(st.top()==-1){
				val=1;
				st.pop();
				st.push(val);
			}
			else{
				while(!st.empty() && st.top()!=-1){
					val+=st.top();
					st.pop();
				}
				st.pop();
				st.push(2*val);
			}
		}
	}

	int ans=0;
	while(!st.empty()){
		ans+=st.top();
		st.pop();
	}

	return ans;
}

int main(){
	
	string str="(()())()()";
	cout << scoreOfParentheses(str) << endl;

	return 0;
}