#include <bits/stdc++.h>
using namespace std;

bool validStackSequence(vector<int> pushed, vector<int> popped){

	stack<int> st;
	int j=0;
	for(int i=0; i<pushed.size(); i++){
		st.push(pushed[i]);
		while(!st.empty() && st.top()==popped[j]){
			st.pop();
			j++;
		}
	}

	return st.empty()?0:1;
}

int main(){
	

	return 0;
}