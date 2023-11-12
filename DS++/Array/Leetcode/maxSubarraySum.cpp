#include <bits/stdc++.h>
using namespace std;

//Kadanes' algorithm
int maxSubarraySum(vector<int>& nums){

	int msf=INT_MIN, ans=nums[0];
	for(int i=0; i<nums.size(); i++){
		msf+=nums[i];
		msf=max(msf, nums[i]);
		ans=max(ans, msf);
	}

	return ans;
}

//MaxProduct subarray 
int maxProduct(vector<int>& nums){

	int maxSum=nums[0], minSum=nums[0], ans=nums[0];
	for(int i=1; i<nums.size(); i++){
		if(nums[i]<0){
			swap(minSum, maxSum);
		}
		minSum=min(nums[i]*minSum, nums[i]);
		maxSum=max(nums[i]*maxSum, nums[i]);
		ans=max(ans, maxSum);
	}

	return ans;
}

int main(){

	vector<int> nums={1,-1,2,-2,-3,-3,-5,5,-6,6,7,-7,-8,0,10};
	cout << maxSubarraySum(nums) << endl;

	return 0;
}