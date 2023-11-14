#include <bits/stdc++.h>
using namespace std;


string minWindow(string str, string t){

	unordered_map<char, int> m;
	int required=0;
	for(int i=0; i<t.size(); i++){
		m[t[i]]++;
		if(m[t[i]]==1){
			required++;
		}
	}

	int start=0, end=0;
	int length=INT_MAX, startIndex=-1;
	while(start<=end && end<str.size()){
		m[str[end]]--;
		if(m[str[end]]==0){
			required--;
		}
		while(required==0 && start<=end){
			if(length>end-start+1){
				length=end-start+1;
				startIndex=start;
			}
			m[str[start]]++;
			if(m[str[start]]==0){
				required++;
			}
			start++;
		}
		end++;
	}

	if(startIndex==-1){
		return "";
	}

	return str.substr(startIndex, length);
}

int main(){
	
	string str="";
	string t="";
	string ans=minWindow(str, t);
	cout << ans << endl;

	return 0;
}