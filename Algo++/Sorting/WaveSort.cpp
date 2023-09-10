#include <bits/stdc++.h>
using namespace std;

void swap(int nums[], int i, int j){
	int temp=nums[j];
	nums[j]=nums[i];
	nums[i]=temp;
}
// 1 3 4 7 5 6 2 // 6 2 5
void waveSort(int nums[], int n){
	for (int i=1; i<n; i+=2){ // i+=2, have to cover only alternative element
		if (nums[i]>nums[i-1]){
			swap(nums,i,i-1);
		} 
		if (nums[i]>nums[i+1] && i<=n-2){
			swap(nums,i,i+1);
		}
	}
}
int main(){
	
	int n;
	cin >> n;
	int nums[n];
	for(int i=0; i<n; i++){
		cin >> nums[i];
	}
	waveSort(nums,n);
	for (int i=0; i<n; i++){
		cout << nums[i] << " ";
	} cout << endl;

	return 0;
}
