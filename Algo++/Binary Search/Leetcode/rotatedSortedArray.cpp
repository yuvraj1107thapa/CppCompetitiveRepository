#include <bits/stdc++.h>
using namespace std;

//Find minimum value in rotated sorted array
int findMin(vector<int>& nums){

	int n=nums.size();
	int st=0, end=nums.size()-1;
	while(st<=end){
		int mid=(st+end)/2;
		int prev=(mid+n-1)%n;
		int next=(mid+1)%n;
		if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
			return nums[mid];
		}
		else if(nums[0]<=nums[mid]){
			st=mid+1;
		}
		else{
			end=mid-1;
		}
	}

	return -1;
}

//Find minimum element in rotated sorted array containing duplicates
int findMin2(vector<int>& nums){

	int st=0, end=nums.size()-1;
	while(st<=end){
		int mid=(st+end)/2;
		if(nums[mid]>nums[end]){
			st=mid+1;
		}
		else if(nums[mid]<nums[end]){
			end=mid;
		}
		else{
			end--;
		}
	}

	return nums[st];
}

//Search in rotated sorted array
int search(vector<int>& nums, int target){

	int st=0, end=nums.size()-1;
	while(st<=end){
		int mid=(st+end)/2;
		if(nums[mid]==target){
			return mid;
		}
		else if(nums[st]<=nums[mid]){
			if(target>=nums[st] && target<=nums[mid]){
				end=mid-1;
			}
			else{
				st=mid+1;
			}
		}
		else{
			if(target>=nums[mid] && target<=nums[end]){
				st=mid+1;
			}
			else{
				end=mid-1;
			}
		}
	}

	return -1;
}

//Search in rotated sorted array containing duplicates
bool search2(vector<int>& nums, int target){

	int st=0, end=nums.size()-1;
	while(st<=end){
		int mid=(st+end)/2;
		if(nums[mid]==target || nums[st]==target || nums[end]==target){
			return true;
		}
		else if(nums[mid]==nums[end]){
			end--;
		}
		else if(nums[st]<=nums[mid]){
			if(target>=nums[st] && target<=nums[mid]){
				end=mid-1;
			}
			else{
				st=mid+1;
			}
		}
		else{
			if(target>=nums[mid] && target<=nums[end]){
				st=mid+1;
			}
			else{
				end=mid-1;
			}
		}
	}

	return false;
}

int main(){
	
	vector<int> nums={6,7,10,1,3,5};
	cout << search(nums, 6) << endl;

	return 0;
}