#include <bits/stdc++.h>
using namespace std;



bool isValid(string str){

	stack<char> st;
	for(int i=0; i<str.size(); i++){
		if(str[i]=='c'){
			if(st.top()!='b'){
				return false;
			}
			st.pop();
			if(st.top()!='a'){
				return false;
			}
		}
		else{
			st.push(str[i]);
		}
	}

	return st.empty();
}

int main(){
	

	return 0;
}