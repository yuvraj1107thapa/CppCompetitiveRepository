#include <bits/stdc++.h>
using namespace std;

vector<int> differentWaysToAddParentheses(string str){

	vector<int> ans;
	for(int i=0; i<str.size(); i++){
		char ch=str[i];
		if(ch=='+' || ch=='*' || ch=='-'){
			vector<int> left, right;
			left=differentWaysToAddParentheses(str.substr(0, i));
			right=differentWaysToAddParentheses(str.substr(i+1));
			for(int j=0; j<left.size(); j++){
				for(int k=0; k<right.size(); k++){
					if(ch=='+') ans.push_back(left[j]+right[k]);
					if(ch=='*') ans.push_back(left[j]*right[k]);
					if(ch=='-') ans.push_back(left[j]-right[k]);
				}
			}
		}
	}

	if(ans.size()>0){
		return ans;
	}
	else{
		ans.push_back(stoi(str));
		return ans;
	}
}

int main(){

	string str="6-6-6";
	vector<int> ans;
	ans=differentWaysToAddParentheses(str);
	cout << "[";
	for(int i=0; i<ans.size(); i++){
		if(i==ans.size()-1){
			cout << ans[i];
			break;
		}
		cout << ans[i] << ",";
	}

	cout << "]";

	return 0;
}