#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& nums){

	for(int i=0; i<nums.size(); i++){
		for(int j=i; j<nums[0].size(); j++){
			int temp=nums[i][j];
			nums[i][j]=nums[j][i];
			nums[j][i]=temp;
		}
	}

	for(int i=0; i<nums.size(); i++){
		reverse(nums[i].begin(), nums[i].end());
	}

}

int main(){

	vector<vector<int>> nums={{1,2,3},{4,5,6},{7,8,9}};
	rotate(nums);
	for(int i=0; i<nums.size(); i++){
		for(int j=0; j<nums[0].size(); j++){
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}