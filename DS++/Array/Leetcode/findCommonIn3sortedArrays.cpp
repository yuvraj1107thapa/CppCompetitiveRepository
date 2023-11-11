#include <bits/stdc++.h>
using namespace std;

//Find common elements in three sorted arrays
vector<int> commonElements(int nums1[], int nums2[], int nums3[], int n1, int n2, int n3){

	vector<int> result;
	int i,j,k;
	i=j=k=0;
	while(i<n1 && j<n2 && k<n3){
		if(nums1[i]==nums2[j] && nums2[j]==nums3[k]){
			result.push_back(nums1[i]);
		}
		else if(nums1[i]<nums2[j]){
			i++;
		}
		else if(nums2[j]<nums3[k]){
			j++;
		}
		else{
			k++;
		}
		int temp=nums1[i-1];
		while(nums1[i]==temp) i++;
		temp=nums2[j-1];
		while(nums2[j]==temp) j++;
		temp=nums3[k-1];
		while(nums3[k]==temp) k++;
	}

	return result;
}

int main(){

	int nums1[]={1,2,3,4,5,10;
	int nums2[]={1,4,6,7,8,10};
	int nums3[]={0,1,2,4,5,10};
	vector<int> ans=commonElements(nums1, nums2, nums3, 6, 6, 6);
	if(ans.size()==0){
		cout << "-1" << endl;
	}
	else{
		for(auto i: ans){
			cout << i << " ";
		}
	}

	return 0;
}