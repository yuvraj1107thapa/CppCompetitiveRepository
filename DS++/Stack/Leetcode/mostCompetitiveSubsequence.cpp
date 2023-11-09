#include <bits/stdc++.h>
using namespace std;



vector<int> mostCompetitive(vector<int>& nums, int k){

	vector<int> st;
	for(int i=0; i<nums.size(); i++){
		while(st.size()>0 && st[st.size()-1]>nums[i] && nums.size()-i-1 <= k-st.size()){
			st.pop_back();
		}
		if(st.size()<k){
			st.push_back(nums[i]);
		}
	}

	return st;
}

int main(){
	
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}

	vector<int> ans=mostCompetitive(nums, k);

	return 0;
}