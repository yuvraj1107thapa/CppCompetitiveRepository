#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int>& nums, int mid, int l, int r){

	long long inv=0;

	int n1=mid-l+1;
	int n2=r-mid;
	vector<int> temp1(n1);
	vector<int> temp2(n2);
	for(int i=0; i<n1; i++){
		temp1[i]=nums[l+i];
	}
	for(int i=0; i<n2; i++){
		temp2[i]=nums[mid+i+1];
	}

	int i=0, j=0, k=l;
	while(i<n1 && j<n2){
		if(temp1[i]<=temp2[j]){
			nums[k++]=temp1[i++];
		}
		else{
			inv+=n1-i;
			nums[k++]=temp2[j++];
		}
	}

	while(i<n1){
		nums[k++]=temp1[i++];
	}
	while(j<n2){
		nums[k++]=temp2[j++];
	}

	return inv;
}

long long inversions(vector<int>& nums, int l, int r){

	long long inv=0;
	if(l<r){
		int mid=(l+r)/2;
		inv+=inversions(nums, l, mid);
		inv+=inversions(nums, mid+1, r);
		inv+=merge(nums, mid, l, r);
	}

	return inv;
}

int main(){

	vector<int> nums={6,5,4,3,2,1};
	cout << inversions(nums, 0, nums.size()-1) << endl;

	return 0;
}