#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <math.h>
using namespace std;

int precedence(char s){
	
	if (s=='^'){
		return 3;
	}
	else if (s=='*' || s=='/'){
		return 2;
	}
	else if (s=='+' || s=='-'){
		return 1;
	}
	else {
		return -1;
	}
}

string reverse(string s){ 
	
	stack<char>st;
	string ans;
	
	for(int i=0; i<s.length(); i++){
		st.push(s[i]);
	}
	
	while(!st.empty()){
		ans+=st.top();
		st.pop();
	}
	
	return ans;
}

string infixToPrefix(string str){
	
	stack<char>st;
	string s = reverse(str);
	
	int i=0;
	while(i<s.length()){
		
		if (s[i]==')'){
			s[i]='(';
		} 
		else if (s[i]=='('){
			s[i]=')';
		}
		
		i++;
	}
	
	string res;
	for (int i=0; i<s.length(); i++){
		
		if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
			res+=s[i];
		}
		else if (s[i]=='('){
			st.push(s[i]);
		}
		else if (s[i]==')'){
			while(!st.empty() && st.top()!='('){
				res+=st.top();
				st.pop();
			}
			if(!st.empty()){
			st.pop();
			}
		}
		else {
			while(!st.empty() && precedence(st.top()) >= precedence(s[i])){
				res+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}

	reverse(res.begin(),res.end());
	return res;
	
}
int main(){
	string s="(a-b/c)*(a/k-l)";
	cout << infixToPrefix(s) << endl;
	return 0;
}
