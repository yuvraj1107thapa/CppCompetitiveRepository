#include <bits/stdc++.h>
using namespace std;



//Given n size array, it has all distinct elements from 0 to n-1
int maxChunks(vector<int> nums){

	int maxsf=0, ans=0;
	for(int i=0; i<nums.size(); i++){
		maxsf=max(maxsf, nums[i]);
		if(maxsf==i){
			ans++;
		}
	}

	return ans;
}


// Observation: A chunk can only be created, if I am at ith index and maximum of all elements at left of it 
// is smaller than this element and it is smaller than minimum of all the element at right of it, so that 
// means I can have a chunk here.

// Idea: So with this observation, If I create maximum so far from left to right as I have to check maximum
// in left and also create minimum so far from right to left as I have to check minimum in right.
// To handle last chunk, I can add INT_MAX value at last of minR
    
// E.g., nums=[3,2,1,5,6,9,7]

//                 i
//       MaxL=[3,3,3,5,6,9,9]; 
//       MinR=[1,1,1,5,6,7,7,INT_MAX];
       


int maxChunks2(vector<int> nums){

	vector<int> rightMin(nums.size());
	int minsf=INT_MAX;
	for(int i=nums.size()-1; i>=0; i--){
		minsf=min(minsf, nums[i]);
		rightMin[i]=minsf;
	}

	int ans=0;
	int leftMax=INT_MIN;
	for(int i=0; i<nums.size(); i++){
		leftMax=max(leftMax, nums[i]);
		if(leftMax<=rightMin[i]){
			ans++;
		}
	}
	ans++;

	return ans;
}


int main(){
	
	return 0;
}