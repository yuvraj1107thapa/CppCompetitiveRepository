#include <bits/stdc++.h>
using namespace std;

//Rearrange array in alternating positive & negative items with O(1) extra space
// i-,j+
// {-5, 5, -2, 2, 4, 7, 1, 8, 0, -8}

//  -5 5 -2 2 -8 7 1 8 0 4

//{-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}

//                                k
// {-5, 5, -2, 2, -8, 7, 1, 8, 0, 4}
//  0   1   2  3   4  5  6  7  8  9
//                                i            

// k%2=0
// i=k

// k%2!=0
// j=k

// Algorithm
// 1. 3 pointer approach = i,j & k;
// 2. i for - and j for + and k for traversing
// 3. odd = - and even = +
// 4. if(odd = +) than i=j=k, find - with i, temp=ith element, left shift till i>j(i--), kth element = temp;
// 5. if(even = -) than i=j=k, find + with j, temp=jth element, left shift till j>i(j--), kth element = temp;
// 6. Doing rotation instead swap as I have to maintain its order



void rearrange(vector<int> &nums, int n){

	int i,j;
	for(int k=0; k<n; k++){
		if(k%2==0){
			if(nums[k]>0){
				i=k;
				j=k;
				while(i<n && nums[i]>=0){
					i++;
				}
				if(i<n){
					int temp=nums[i];
					while(i>j){
						nums[i]=nums[i-1];
						i--;
					}
					nums[k]=temp;
				}	
			}
		}
		else if(k%2!=0){
			if(nums[k]<0){
				i=k;
				j=k;
				while(j<n && nums[j]<0){
					j++;
				}
				if(j<n){
					int temp=nums[j];
					while(j>i){
						nums[j]=nums[j-1];
						j--;
					}
					nums[k]=temp;
				}
			}
		}
	}

}

int main(){

	vector<int> nums={-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
	rearrange(nums, 10);
	for(int i=0; i<10; i++){
		cout << nums[i] << " ";
	}

	return 0;
}