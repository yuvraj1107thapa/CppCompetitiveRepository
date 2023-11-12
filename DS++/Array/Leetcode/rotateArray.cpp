#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& nums, int st, int end){

	while(st<=end){
		swap(nums[st++], nums[end--]);
	}
}

void rotateArray(vector<int>& nums, int k){

	reverse(nums, 0, k);
	reverse(nums, k+1, nums.size()-1);
	reverse(nums, 0, nums.size()-1);

}

void rotateArrayByOne(vector<int>& nums){

	int temp=nums[0];
	for(int i=0; i<nums.size()-1; i++){
		nums[i]=nums[i+1];
	}
	nums[nums.size()-1]=temp;

}

int main(){

	vector<int> nums={0,1,2,3,4,5,6,7,8,9,10};
	rotateArrayByOne(nums);
	for(auto i: nums){
		cout << i << " ";
	}
	cout << endl;

	return 0;
}