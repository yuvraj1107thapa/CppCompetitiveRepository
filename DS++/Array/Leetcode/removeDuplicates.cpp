#include <bits/stdc++.h>
using namespace std;



//Remove duplicates in sorted array
int removeDupicates(vector<int>& nums){

	int p=1;
	for(int i=1; i<nums.size(); i++){
		if(nums[i]!=nums[i-1]){
			nums[p++]=nums[i];
		}
	}

	return p;
}

//Remove duplicates in sorted array if duplicates is more than 2
int removeDuplicates2(vector<int>& nums){

	int p=1, counter=1;
	for(int i=1; i<nums.size(); i++){
		if(nums[i]==nums[i-1]){
			if(counter<2){
				nums[p++]=nums[i];
			}
			counter++;
		}
		else{
			counter=1;
			nums[p++]=nums[i];
		}
	}

	return p;
}


int main(){
	
	vector<int> nums={1,1,1,2,2,2,3,3,3,6,6,6,7};
	for(int i=0; i<nums.size(); i++){
		cout << nums[i] << " ";
	}
	cout << endl;

	int n=removeDuplicates2(nums);
	for(int i=0; i<n; i++){
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}