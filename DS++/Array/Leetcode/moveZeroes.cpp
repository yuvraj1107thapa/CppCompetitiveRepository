#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums){

	int p=0;
	for(int i=0; i<nums.size(); i++){
		if(nums[i]){
			swap(nums[i], nums[p++]);
		}
	}

}

int main(){
	
	vector<int> nums={1,0,2,0,0,0,0,0,5,6,7,8,9};
	moveZeroes(nums);
	for(auto i: nums){
		cout << i << " ";
	}
	cout << endl;

	return 0;
}