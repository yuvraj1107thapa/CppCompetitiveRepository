#include <bits/stdc++.h>
using namespace std;

void combinationSum(vector<int> nums, int target, vector<vector<int>>& ans, vector<int> ds, int idx){

	if(target<0){
		return;
	}
	if(target==0){
		ans.push_back(ds);
		return;
	}

	for(int i=idx; i<nums.size(); i++){
		ds.push_back(nums[i]);
		combinationSum(nums, target-nums[i], ans, ds, i);
		ds.pop_back();
	}
}


int main(){

	vector<int> nums={1,2,3,4,5,6,7};
	vector<vector<int>> ans;
	vector<int> ds;
	combinationSum(nums, 7, ans, ds, 0);
	for(int i=0; i<ans.size(); i++){
		for(int j=0; j<ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}