#include <bits/stdc++.h>
using namespace std;

//Kth min element using priority queue
//Idea: Pop top element when queue.size>k -> It's always pop max element

int kthMinElement(vector<int>& nums, int k){

	priority_queue<int> ans;
	for(int i=0; i<nums.size(); i++){
		ans.push(nums[i]);
		if(ans.size()>k){
			ans.pop();
		}
	}

	return ans.top();
}
 
//Kth max element using priority queue
//Idea: Pop top element when queue.size>k -> It's always pop min element

int kthMaxElement(vector<int>& nums, int k){

	priority_queue<int, vector<int>, greater<int>> ans;
	for(int i=0; i<nums.size(); i++){
		ans.push(nums[i]);
		if(ans.size()>k){
			ans.pop();
		}
	}

	return ans.top();
}

int main(){

	vector<int> nums={1,2,3,4,5,6};
	cout << kthMinElement(nums, 5) << endl;
	cout << kthMaxElement(nums, 5) << endl;

	return 0;
}