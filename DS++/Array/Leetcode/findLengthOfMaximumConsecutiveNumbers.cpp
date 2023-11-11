#include <bits/stdc++.h>
using namespace std;



int maxConsecutiveNums(vector<int>& nums){

	unordered_set<int> m;
	for(int i=0; i<nums.size(); i++){
		m.insert(nums[i]);
	}

	int maxLength=0;
	for(int i=0; i<nums.size(); i++){
		if(!m.count(nums[i]-1)){
			int currentNum=nums[i];
			int currentLength=1;
			while(m.count(currentNum+1)){
				currentLength++;
				currentNum++;
			}
			maxLength=max(maxLength, currentLength);
		}
	}

	return maxLength;
}

int main(){

	vector<int> nums={1,2,3,4,5,6,10,15,17,7};
	cout << maxConsecutiveNums(nums) << endl;

	return 0;
}
