#include <bits/stdc++.h>
using namespace std;

vector<int> findSubarray(vector<int>& nums, int target){

	vector<int> ans;
	int i=0, j=0, sum=0;

	while(j<nums.size() && nums[j]+sum<target){
		sum+=nums[j++];
	}
	if(sum==target){
		ans.push_back(i+1);
		ans.push_back(j);
		return ans;
	}

	while(j<nums.size()){
		sum+=nums[j];
		while(sum>target){
			sum-=nums[i++];
		}
		if(sum==target){
			ans.push_back(i+1);
			ans.push_back(j+1);
			return ans;
		}
		j++;
	}

	return ans;
}

int main(){
	
	vector<int> nums={1,2,3,4,5,6,1,7};
	vector<int> ans=findSubarray(nums, 6);
	for(auto i: ans){
		cout << i << " ";
	}
	cout << endl;

	return 0;
}