#include <iostream>
using namespace std;

// Algorithm
// Boyer's Moore majority voting algorithm
// 1. Make 2 variables: count=candidate=0, candidate for storing majority element if present, 
// 2. Run a loop 0 to arraySize-1
// 3. Check if count==0, update candidate with current element 
// 4. Check if current element is equal to previous candidate, if yes, count++
// 5. Else count--
// 6. Traverse through array again and count the number of elements equal to candidate, after that 
//    if count>arraySize/2, candidate is the majority element else there is no majority element


//Find a majority element that appears more than n/2 times
int majorityElement(int nums[], int n){

	int count=0;
	int candidate=0;
	for(int i=0; i<n; i++){
		if(count==0){
			candidate=nums[i];
		}
		if(nums[i]==candidate){
			count++;
		}
		else{
			count--;
		}
	}
	count=0;
	for(int i=0; i<n; i++){
		if(nums[i]==candidate){
			count++;
		}
	}

	if(count<n/2){
		return -1;
	}
	return candidate;
}

//Find majority element that appears more than n/3 times
int majorityElement2(vector<int>& nums){

	int count1=0, count2=0;
	int candidate1=0, candidate2=0;

	for(int i=0; i<nums.size(); i++){
		if(count1==0 && nums[i]!=candidate2){
			candidate1=nums[i];
			count1=1;
		}
		else if(count2==0 && nums[i]!=candidate1){
			candidate2=nums[i];
			count2=1;
		}
		else if(candidate1==nums[i]){
			count1++;
		}
		else if(candidate2==nums[i]){
			count2++;
		}
		else{
			count1--;
			count2--;
		}
	}

	count1=0, count2=0;
	for(int i=0; i<nums.size(); i++){
		if(candidate1==nums[i]){
			count1++;
		}
		else if(candidate2==nums[i]){
			count2++;
		}
	}

	vector<int> ans;
	if(count1>nums.size()/3){
		ans.push_back(candidate1);
	}
	if(count2>nums.size()/3){
		ans.push_back(candidate2);
	}

	return ans;
}

int main(){

	int n;
	cout << "Enter size: ";
	cin >> n;
	int arr[n];
	cout << "Enter element: ";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	int res=majorityElement(arr, n);
	if(res!=-1){
		cout << "Majority Element: " << res << endl;
	}
	else{
		cout << "There is no majority element." << endl;
	}

	return 0;
}