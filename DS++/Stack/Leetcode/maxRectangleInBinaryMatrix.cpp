#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int>& heights){

	stack<pair<int,int>> st;
		vector<int> left;
		for(int i=0; i<heights.size(); i++){
			if(st.size()==0){
				left.push_back(-1);
			}
			else if(st.size()>0 && st.top().first<heights[i]){
				left.push_back(st.top().second);
			}
			else if(st.size()>0 && st.top().first>=heights[i]){
				while(!st.empty() && st.top().first>=heights[i]){
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

	return left;
}

vector<int> NSR(vector<int>& heights){

	stack<pair<int,int>> st;
	vector<int> right;
		for(int i=heights.size()-1; i>=0; i--){
			if(st.size()==0){
				right.push_back(heights.size());
			}
			else if(st.size()>0 && st.top().first<heights[i]){
				right.push_back(st.top().second);
			}
			else if(st.size()>0 && st.top().first>=heights[i]){
				while(!st.empty() && st.top().first>=heights[i]){
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

	return right;
}

int maxAreaHistogram(vector<int> &heights){

	int maxArea=0;

	vector<int> left=NSL(heights);
	vector<int> right=NSL(heights);
	vector<int> width(heights.size());
	for(int i=0; i<heights.size(); i++){
		width[i]=right[i]-left[i]-1;
		maxArea=max(maxArea, heights[i]*width[i]);
	}

	return maxArea;
}

int maximalRectangle(vector<vector<int>>& matrix) {
        
    int maxRectangle=0;
    
    vector<int> temp(matrix[0].size());
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[i][j]==0){
                temp[j]=0;
            }
            else{
                temp[j]+=matrix[i][j];
            }
        }
        maxRectangle=max(maxRectangle, maxAreaHistogram(temp));
    }
    
    return maxRectangle;
}

int main(){

	vector<vector<int>> matrix={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
	cout << maximalRectangle(matrix) << endl;

	return 0;
}