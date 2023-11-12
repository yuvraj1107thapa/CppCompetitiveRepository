#include <bits/stdc++.h>
using namespace std;

void zeroOneTwoSort(vector<int>& nums){

	int st=0, mid=0, end=nums.size()-1;
	while(mid<=end){
		if(nums[mid]==0){
			swap(nums[st], nums[mid]);
			st++; mid++;
		}
		else if(nums[mid]==1){
			mid++;
		}
		else{
			swap(nums[mid], nums[end]);
			end--;
		}
	}

}

int main(){

	vector<int> nums={0,1,2,0,1,2};
	zeroOneTwoSort(nums);
	for(auto i: nums){
		cout << i << " ";
	}
	cout << endl;

	return 0;
}