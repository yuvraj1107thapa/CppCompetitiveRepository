#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> nums){

	int st=0, end=nums.size()-1;
	while(st<=end){
		int mid=(st+end)/2;
		if(mid>0 || mid<nums.size()-1){
			if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
				return mid;
			}
			else if(nums[mid+1]>nums[mid]){
				st=mid+1;
			}
			else{
				end=mid-1;
			}
		}
		else if(mid==0){
			if(nums[0]>nums[1]){
				return 0;
			}
			else{
				return 1;
			}
		}
		else if(mid==nums.size()-1){
			if(nums[nums.size()-1]>nums[nums.size()-2]){
				return nums.size()-1;
			}
			else{
				return nums.size()-2;
			}
		}
	}


	return -1;
}

int main(){
	
	vector<int> nums={10,2,5,6,2,1,7};
	cout << findPeakElement(nums) << endl;

	return 0;
}