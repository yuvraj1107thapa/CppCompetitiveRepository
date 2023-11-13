#include <bits/stdc++.h>
using namespace std;

//Power set of string
void subsequence(string s, int ans){

	if(s.length()==0){
		cout << ans << endl;
		return;
	}

	char ch=s[0];
	string ros=s.substr(1);
	subsequence(ros, ans);
	subsequence(ros, ans+ch);

}

// Algorithm
// 1. Idea: for every idx element, I have two choices, either take that element or not take that element
// 2. So, when I have choices and I can make ans with that choices, I can use recursion to solve that question

//Power set of vector
void subsequence2(vector<int>& nums, vector<vector<int>>& ans, vector<int> ds, int idx){

	if(idx>=nums.size()){
		ans.push_back(ds);
		return;
	}

	subsequence2(nums, ans, ds, idx+1);
	ds.push_back(nums[idx]);
	subsequence2(nums, ans, ds, idx+1);
}

// Algorithm
// 1. At first, push ds to my ans vector 
// 2. i=idx to n-1, check if i!=idx & current element not equal to previous element than push element to my ds than call 
// 	  recursion with i+1, after recursive call do backtrack means pop that current element from ds so that ds will not 
//    have that previous element which I push to my ds before recursion because than only it will generate unique subsets
// 3. i is making sure than ds will not contains duplicates

//Power set if vector contains duplicates
void uniqueSubset(vector<int>& nums, vector<vector<int>>& ans, vector<int> ds, int idx){

	ans.push_back(ds);

	for(int i=idx, i<nums.size(); i++){
		if(i!=idx && nums[i]==nums[i-1]) continue;
		ds.push_back(num[i]);
		uniqueSubset(nums, ans, ds, i+1);
		ds.pop_back();
	}
}

int main(){

	vector<int> nums={1,2,3};
	vector<vector<int>> result;
	vector<int> ds;
	subsequence2(nums, result, ds, 0);
	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[i].size(); j++){
			cout << result[i][j];
		}
		cout << endl;
	}

