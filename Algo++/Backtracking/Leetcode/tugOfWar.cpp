#include <bits/stdc++.h>
using namespace std;

//tug of war
void dfs(vector<int>& nums, vector<int> subs1, vector<int> subs2, int sum1, int sum2, int idx, int currentAns, string& ans){

	if(idx==nums.size()){
		if(abs(sum1-sum2)<currentAns){
			currentAns=abs(sum1-sum2);
			ans=to_string(sum1)+" "+to_string(sum2);
		}
		return;
	}

	if(subs1.size()<(nums.size()+1)/2){
		subs1.push_back(nums[idx]);
		dfs(nums, subs1, subs2, sum1+nums[idx], sum2, idx+1, currentAns, ans);
		subs1.pop_back();
	}

	if(subs2.size()<(nums.size()+1)/2){
		subs2.push_back(nums[idx]);
		dfs(nums, subs1, subs2, sum1, sum2+nums[idx], idx+1, currentAns, ans);
		subs2.pop_back();
	}
}

int main(){
		
	vector<int> nums={1,2,3,4,5,6};
	vector<int> subs1, subs2;
	int sum1=0, sum2=0;
	int currentAns=INT_MAX;
	string ans="";
	dfs(nums, subs1, subs2, sum1, sum2, 0, currentAns, ans);
	cout << ans << endl;

	return 0;
}