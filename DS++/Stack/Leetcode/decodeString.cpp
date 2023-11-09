#include <bits/stdc++.h>
using namespace std;

string decodeString(string s){

	stack<char> st;
	for(int i=0; i<s.size(); i++){
		if(s[i]!=']'){
			st.push(s[i]);
		}
		else{

			string str="";

			while(!st.empty() && st.top()>='a' && st.top()<='z'){
				str=st.top()+str;
				st.pop();
			}
			st.pop();

			string num="";
			while(!st.empty() && st.top()>='0' && st.top()<='9'){
				num=st.top()+num;
				st.pop();
			}

			int k=stoi(num);
			while(k){
				for(int j=0; j<str.size(); j++){
					st.push(str[j]);
				}
				k--;
			}
		}
	}

	string ans="";
	while(!st.empty()){
		ans=st.top()+ans;
		st.pop();
	}

	return ans;
}

int main(){
	
	string s="3[y]";
	string ans=decodeString(s);
	cout << ans << endl;


	return 0;
}