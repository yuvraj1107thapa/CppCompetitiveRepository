#include <bits/stdc++.h>
using namespace std;

// Algorithm
// 1. Sort vector of vector, intervals[i] = [starti, endi]
// 2. Make vector of vector for storing result
// 3. Run a loop 0 to n -> i
// 4. Check if i==sizeOfVector-1, if yes, push_back(current intervals[i]) to result
// 5. Else if currentIntervals[end]>=nextIntervals[start], if yes, then nextInterval[start]=currentInterval[start]
//    and store maximum of currentIntervals[end] or nextIntervals[end] to nextInterval[end]
// 6. Else push_back(current intervals[i]) to result

//Merge the overlapping intervals
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){

	if(intervals.size()==0) return intervals;

	sort(intervals.begin(), intervals.end());
	vector<vector<int>> result;
	int n=intervals.size();
	for(int i=0; i<n; i++){
		if(i==n-1){
			result.push_back(intervals[i]);
		}
		else if(intervals[i][1]>=intervals[i+1][0]){
			intervals[i+1][0]=intervals[i][0];
			intervals[i+1][1]=max(intervals[i][1], intervals[i+1][1]);
		}
		else{
			result.push_back(intervals[i]);
		}
	}

	return result;
}

int main(){

	vector<vector<int>> intervals={{1,2},{2,4},{5,8},{10,12},{6,8},{15,21}};
	vector<vector<int>> result=mergeIntervals(intervals);
	for(int i=0; i<result.size(); i++){
		for(int j=0; j<result[0].size(); j++){
			cout << result[i][j] << ",";
		}
		cout << " ";
	}

	return 0;
}