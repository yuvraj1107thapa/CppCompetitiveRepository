#include <bits/stdc++.h>
using namespace std;

//Letter combination of a phone number
void dfs(string digits, vector<string> letter, vector<string>& ans, string st, int idx){

	if(idx==digits.size()){
		ans.push_back(st);
		return;
	}

	char ch=digits[idx];
	string digitLetters=letter[ch-'0'];

	for(int i=0; i<digitLetters.size(); i++){
		st+=digitLetters[i];
		dfs(digits, letter, ans, st, idx+1);
		st.pop_back();
	}
}

vector<string> letterCombination(string digits, vector<string> letter){

	vector<string> ans;
	if(digits.size()==0){
		return ans;
	}
	dfs(digits, letter, ans, "", 0);

	return ans;
}

int main(){

	vector<string> letter={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> ans;
	string digits;
	cin >> digits;
	ans=letterCombination(digits, letter);
	for(int i=0; i<ans.size(); i++){
		for(int j=0; j<ans[0].size(); j++){
			cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}