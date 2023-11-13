#include <bits/stdc++.h>
using namespace std;

bool subset(vector<int>& nums, vector<bool>& visited, int currentSum, int target, int k, int idx){

	if(k==1){
		return true;
	}
	if(currentSum==target){
		return subset(nums, visited, currentSum, target, k-1, 0);
	}

	for(int i=idx; i<nums.size(); i++){
		if(visited[i] || currentSum+nums[i]>target){
			continue;
		}
		visited[i]=1;
		if(subset(nums, visited, currentSum+nums[i], target, k, i+1)){
			return true;
		}
		visited[i]=0;
	}

	return false;
}

bool equalSumPartition(vector<int>& nums, int k){

	long long sum=0;
	for(int i=1; i<nums.size(); i++){
		sum+=nums[i];
	}
	if(nums.size()<k || sum%k!=0){
		return false;
	}

	int currentSum=0;
	vector<bool> visited(nums.size(), false);

	return subset(nums, visited, currentSum, sum/k, k, 0);
}

int main(){

	vector<int> nums={1,2,3,4,5,6};
	int k=3;
	cout << equalSumPartition(nums, k) << endl;

	return 0;
}