#include <bits/stdc++.h>
using namespace std;

//Check if second array is subset of first array or not
bool subset(vector<int> nums1, vector<int> nums2){

		unordered_map<int,int> m;
		for(int i=0; i<nums1.size(); i++){
			m[nums1[i]]++;
		}
		bool flag=1;
		for(int i=0; i<nums2.size(); i++){
			if(!m[nums2[i]]){
				flag=0;
				break;
			}
		}

		if(flag==1){
			return 1;
		}
		else{
			return 0;
		}
}

int main(){

	vector<int> nums1={1,10,5,1,2,2,11,12,15,18};
	vector<int> nums2={1,2,5,8};
	if(subset(nums1, nums2)){
		cout << "Yes, It's a subset." << endl;
	} else{
		cout << "No, It's not a subset." << endl;
	}

	return 0;
}