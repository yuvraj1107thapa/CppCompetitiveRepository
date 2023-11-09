#include <bits/stdc++.h>
using namespace std;

int calculate(string str){

	stack<int> st;
	char sign='+';
	for(int i=0; i<str.size(); i++){
		if(isdigit(str[i])){
			int val=0;
			while(i<str.size() && isdigit(str[i])){
				val=val*10+(str[i]-'0');
				i++;
			}
			i--;

			if(sign=='+'){
				st.push(val);
			}
			if(sign=='-'){
				st.push(-val);
			}
			if(sign=='*'){
				int num=st.top();
				st.pop();
				st.push(num*val);
			}
			if(sign=='/'){
				int num=st.top();
				st.pop();
				st.push(num/val);
			}
		}
		else if(str[i]!=' '){
			sign=str[i];
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
	
	string str="5*3+6";
	cout << calculate(str) << endl;

	return 0;
}