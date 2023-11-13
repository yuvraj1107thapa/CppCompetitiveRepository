#include <bits/stdc++.h>
using namespace std;

void recursivePermute(int idx, vector<int>& nums, vector<vector<int>>& ans){

	if(idx==nums.size()){
		ans.push_back(nums);
	}

	for(int i=idx; i<nums.size(); i++){
		swap(nums[i], nums[idx]);
		recursivePermute(idx+1, nums, ans);
		swap(nums[i], nums[idx]);
	}

}

vector<vector<int>> permute(vector<int>& nums){

	vector<vector<int>> ans;
	recursivePermute(0, nums, ans);

	return ans;
}

vector<vector<int>> permute2(vector<int>& nums){

	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	do{
		ans.push_back(nums);
	}while(next_permutation(nums.begin(), nums.end()));

	return ans;
}

void generatePermutation(vector<int> nums, vector<vector<int>>& ans, int idx){

	if(idx==nums.size()){
		ans.push_back(nums);
		return;
	}

	for(int i=idx; i<nums.size(); i++){
		if(i!=idx && nums[i]==nums[i-1]) continue;
		swap(nums[i], nums[idx]);
		generatePermutation(nums, ans, idx+1);
	}

}

vector<vector<int>> uniquePermute(vector<int>& nums){

	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	generatePermutation(nums, ans, 0);

	return ans;
}

// Kth Pemutation
string sequence(int n, int k){

	int fact=1;
	vector<int> nums;
	for(int i=1; i<n; i++){
		fact=fact*i;
		nums.push_back(i);
	}
	nums.push_back(n);

	string ans="";
	k--;

	while(true){
		ans+=to_string(nums[k/fact]);
		nums.erase(nums.begin()+k/fact);
		if(nums.size()==0) break;
		k=k%fact;
		fact=fact/nums.size();
	}

	return ans;
}

int main(){

	string st=sequence(6, 1);
	cout << st << endl;

	return 0;
}