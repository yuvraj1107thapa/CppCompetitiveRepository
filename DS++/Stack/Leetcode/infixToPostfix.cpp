#include <bits/stdc++.h>
using namespace std;
int precedence(char ch){

	if(ch=='*' || ch=='/'){
		return 2;
	}
	else if(ch=='+' || ch=='-'){
		return 1;
	}
	return 0;
}
string infixToPostfix(string infix){

	string postfix;
	stack<char> st;
	for(int i=0; i<infix.size(); i++){
		char ch=infix[i];
		if(isalpha(ch)){
			postfix+=ch;
		}
		else{
			if(!st.empty()){
				while(!st.empty() && precedence(st.top()) >= precedence(ch)){
					postfix+=st.top();
					st.pop();
				}
			}
			st.push(ch);
		}
	}

	while(!st.empty()){
		postfix+=st.top();
		st.pop();
	}	

	return postfix;
}
Observation: To convert infix to postfix, In postfix, operator comes after operand. 
operand operand operator e.g., ij+

Idea: I can use stack to store the operator, and also I can check their precedence like */ have greater precedence
than -+, so if my operand have lesser precedence than the element that is in stack, I will pop that element and 
add to my answer

int main(){
	

	string infix="a+b*c-d/e";
	cout << infixToPostfix(infix) << endl;
	return 0;
}