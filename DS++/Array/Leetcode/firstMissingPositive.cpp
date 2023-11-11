#include <bits/stdc++.h>
using namespace std;

//Using swapSort
int missingNum(vector<int>& nums){

	int i=0;
	while(i<nums.size()){
		if(num[i]>0 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1]{
			swap(nums[i], nums[nums[i]-1]);
		}
		else{
			i++;
		}
	}

	for(int i=0; i<nums.size(); i++){
		if(nums[i]!=i+1){
			return i+1;
		}
	}

	return nums.size()+1;
}

int main(){

	vector<int> nums={5,6,2,1,10,3,4,7,7,8,1,2};
	cout << missingNum(nums) << endl;

	return 0;
}

1,2,3,4,5,6,7,8,7,1,1
0 1 2 3 4 5 6 7 8 9 10
                i
                9 (it is first missing number)                    



