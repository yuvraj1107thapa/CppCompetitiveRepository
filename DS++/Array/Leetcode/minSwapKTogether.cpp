#include <bits/stdc++.h>
using namespace std;
 
// Algorithm
// 1. Windows sliding algorithm
// 2. Count all elements <=k -> fav elements or gharKeLog
// 3. Run a loop 0 till fav-1, find elements >k -> notFav elements or baharKeLog
// 4. Run a loop from fav-1 index till arraySize, 3 variable: st=0, end=k-1, result=notFav
// 5. Each iteration, st++, end++ -> maintaining size of window or house
// 6. If element at end pos >k, yes, notFav++ -> taking notFav inside house
// 7. If element at st pos >k, yes, notFav-- -> puting notFav outside house
// 8. update result with min of prevResult notFav


//minimum swaps to bring element <=k together
int minSwap(vector<int> &nums, int k){

	int fav=0, nonFav=0;
	for(int i=0; i<nums.size(); i++){
		if(nums[i]<=k) fav++;
	}
	for(int i=0; i<fav; i++){
		if(nums[i]>k) nonFav++;
	}
	int st=0, end=fav-1;
	int result=INT_MAX;
	for(int i=fav-1; i<nums.size(); i++){
		end++;
		result=min(result, nonFav);
		if(nums[st++]>k) nonFav--;
		if(nums[end]>k) nonFav++;
	}

	return result;
}

int main(){			
 
	vector<int> nums={2, 7, 9, 5, 8, 7, 4};
	cout << minSwap(nums, 5);

	return 0;
}