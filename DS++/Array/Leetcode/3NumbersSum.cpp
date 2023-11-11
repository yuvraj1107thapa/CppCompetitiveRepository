#include <bits/stdc++.h>
using namespace std;


//Find all three number pairs that's equal to 0
vector<vector<int>> findPairs(vector<int> &nums){

	vector<vector<int>> ans;
	if(nums.size()<3){
		return ans;
	}
	sort(nums.begin(), nums.end());
	for(int i=0; i<nums.size()-2; i++){
		if(i>0 && (nums[i]==nums[i-1])) continue;
		int l=i+1, r=nums.size()-1;
		while(l<r){
			int current=nums[i]+nums[l]+nums[r];
			if(current==0){
				ans.push_back({nums[i], nums[l], nums[r]});
				while(l<r && nums[l]==nums[l-1]) l++;
				while(l<r && nums[r]==nums[r-1]) r--;
				l++; r--;
			}
			else if(current<0){
				l++;
			}
			else{
				r--;
			}
		}
	}

	return ans;
}

//Find three number pairs that's equal to given target
bool isFound(vector<int> &nums, int target){

	if(nums.size()<3){
		return false;
	}
	sort(nums.begin(), nums.end());
	bool found=false;
	for(int i=0; i<nums.size(); i++){
		int l=i+1, r=nums.size()-1;
		while(l<r){
			int current=nums[i]+nums[l]+nums[r];
			if(current==target){
				found=true;
				break;
			}
			else if(current<target){
				l++;
			} 
			else{
				r--;
			}
		}
	}

	return found;
}

//Find three number's sum that is closest to given target
int threeNumbersSumClosest(vector<int> &nums, int target){

	sort(nums.begin(), nums.end());
	int result=nums[0]+nums[1]+nums[nums.size()-1];
	for(int i=0; i<nums.size()-2; i++){
		int l=i+1, r=nums.size()-1;
		while(l<r){
			int current=nums[i]+nums[l]+nums[r];
			if(abs(current-target)<abs(result-target)){
				result=current;
			}	
			if(current<target){
				l++;
			}
			else{
				r--;
			}
		}
	}

	return result;
}

//Find all four number pairs that equals to given target
vector<vector<int>> findPairs2(vector<int> &nums, int target){

	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	for(int i=0; i<nums.size(); i++){
		for(int j=i+1; j<nums.size(); j++){
			int l=j+1, r=nums.size()-1;
			while(l<r){
				int current=nums[i]+nums[j]+nums[l]+nums[r];
				if(current==target){
					result.push_back({nums[i],nums[j],nums[l],nums[r]});
					while(l<r && nums[l]==nums[l+1]) l++;
					while(l<r && nums[r]==nums[r-1]) r--;
					l++; r--;
				}
				else if(current<target){
					l++;
				}
				else{
					r--;
				}
			}
			while(j<nums.size()-1; nums[j]==nums[j+1]) j++;
		}
		while(i<nums.size()-1; nums[i]==nums[i+1]) i++;
	}

	return result;
}


int main(){

	vector<int> nums={-1,0,1,2,0,-1};
	vector<vector<int>> result=findPairs(nums);
	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[0].size(); j++){
			cout << result[i][j] << ",";
		}
		cout << " ";
	}
	
	return 0;
}