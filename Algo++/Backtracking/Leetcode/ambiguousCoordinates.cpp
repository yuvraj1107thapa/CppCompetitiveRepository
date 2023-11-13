#include <bits/stdc++.h>
using namespace std;

bool isValid(string str){

	if(str.size()>1 && str[0]=='0' && str[1]!='.'){
		return false;
	}
	else if(str[str.size()-1]=='0'){
		for(int i=str.size()-1; i>=0; i--){
			if(str[i]=='.'){
				return false;
			}
		}
	}

	return true;
}

vector<string> putDot(string str){

	vector<string> res;
	res.push_back(str);
	for(int i=1; i<str.size(); i++){
		res.push_back(str.substr(0, i)+"."+str.substr(i));
	}

	return res;
}

void solve(vector<string>& ans, string x, string y){

	vector<string> xCoordinate=putDot(x);
	vector<string> yCoordinate=putDot(y);

	for(auto i: xCoordinate){
		if(isValid(i)){
			for(auto j: yCoordinate){
				if(isValid(j)){
					ans.push_back("("+i+", "+j+")");
				}
			}
		}
	}
}

vector<string> ambiguosCoordinates(string s){

	string str=s.substr(1, s.size()-2);
	vector<string> ans;
	for(int i=1; i<str.size(); i++){
		solve(ans, str.substr(0, i), str.substr(i));
	}

	return ans;
}

int main(){
		
	string s="(123)";
	vector<string> ans=ambiguosCoordinates(s);
	for(auto i: ans){
		cout << i << endl;
	}

	return 0;
}