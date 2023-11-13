#include <bits/stdc++.h>
using namespace std;



void dfs(string str, string &ans, int k){

	if(k==0) return;

	for(int i=0; i<str.size()-1; i++){
		for(int j=i+1; j<str.size(); j++){
			if(str[i]<str[j]){
				swap(str[i], str[j]);
				if(str.compare(ans)>0){
					ans=str;
				}
				dfs(str, ans, k-1);
				swap(str[i], str[j]);
			}
		}
	}
}

string findMaximum(string str, int k){

	string ans=str;
	dfs(str, ans, k);
	return ans;

}

int main(){
			
	string str="123456";
	cout << findMaximum(str, 3) << endl;

	return 0;
}