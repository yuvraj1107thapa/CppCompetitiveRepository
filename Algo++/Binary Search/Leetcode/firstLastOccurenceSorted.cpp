#include <bits/stdc++.h>
using namespace std;

// Algorithm
// Binary Search -> Each iteration, divide array into half and search for target
// 3 variables: st=0, end=arraySize-1, result=-1 initially and going to store final result 
// First Occurence, search for target if found, make result=index and end=mid-1, return result
// Last Occurence, search for target if found, make result=index and st=mid+1, return result

//Find first occurence index of target value
int firstOcc(vector<int> nums, int target){

	int st=0, end=nums.size()-1;
	int result=-1;
	while(st<=end){
		int mid=(st+end)/2;
		if(nums[mid]==target){
			result=mid;
			end=mid-1;
		}
		else if(nums[mid]>target){
			end=mid-1;
		}
		else{
			st=mid+1;
		}
	}

	return result;
}

//Find last occurence index of target value
int lastOcc(vector<int> nums, int target){

	int st=0, end=nums.size()-1;
	int result=-1;
	while(st<=end){
		int mid=(st+end)/2;
		if(nums[mid]==target){
			result=mid;
			st=mid+1;
		}
		else if(nums[mid]>target){
			end=mid-1;
		}
		else{
			st=mid+1;
		}
	}

	return result;
}

//Find first and last occurence or position of target value
vector<int> searchRanges(vector<int> &nums, int target){

	int first, last;
	first=firstOcc(nums, target);
	last=lastOcc(nums, target);
	vector<int> ans={first, last};

	return ans;
}

int main(){

	vector<int> nums={1,2,2,2,2,3,4,5,6,6,7};
	vector<int> ranges=searchRanges(nums, 2);
	cout << ranges[0] << endl;
	cout << ranges[1] << endl;

	return 0;
}

search first and last occurence of 2

1,1,1,1,1,1,2,2,2,2,2
0 1 2 3 4 5 6 7 8 9 10
            m
              
st=6
end=7
mid=6
currentAns=6 (first occurence)
while(st<=end)

  
