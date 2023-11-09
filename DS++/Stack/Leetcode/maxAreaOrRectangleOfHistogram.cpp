#include <bits/stdc++.h>
using namespace std;

// Algorithm
// 1. find nearest smallest left building for every ith building
// 2. find nearest smallest right building for every ith building
// 3. Calculate width for every ith building by right[i]-left[i]-1;
// 4. Calculate area for every ith building by widht[i]*heights[i]
// 5. find maxArea

//Calculate maximum area of histogram
int maxAreaHistogram(vector<int> &heights){

	int maxArea=0;

	stack<pair<int,int>> st;
	vector<int> left;
	for(int i=0; i<heights.size(); i++){
		if(st.size()==0){
			left.push_back(-1);
		}
		else if(st.size()>0 && st.top().first<heights[i]){
			left.push_back(st.top().second);
		}
		else if(st.size()>0 && st.top().first>heights[i]){
			while(!st.empty() && st.top().first>heights[i]){
				st.pop();
			}
			if(st.size()==0){
				left.push_back(-1);
			}
			else{
				left.push_back(st.top().second);
			}
		}
		st.push({heights[i], i});
	}

	while(!st.empty()){
		st.pop();
	}
	
	vector<int> right;
	for(int i=heights.size()-1; i>=0; i--){
		if(st.size()==0){
			right.push_back(heights.size());
		}
		else if(st.size()>0 && st.top().first<heights[i]){
			right.push_back(st.top().second);
		}
		else if(st.size()>0 && st.top().first>heights[i]){
			while(!st.empty() && st.top().first>heights[i]){
				st.pop();
			}
			if(st.size()==0){
				right.push_back(heights.size());
			}
			else{
				right.push_back(st.top().second);
			}
		}
		st.push({heights[i], i});
	}
	reverse(right.begin(), right.end());

	vector<int> width(heights.size());
	for(int i=0; i<heights.size(); i++){
		width[i]=right[i]-left[i]-1;
		maxArea=max(maxArea, heights[i]*width[i]);
	}

	return maxArea;
}

int main(){

	vector<int> heights={6,2,5,4,5,1,6};
	cout << maxAreaHistogram(heights) << endl;

	return 0;
}