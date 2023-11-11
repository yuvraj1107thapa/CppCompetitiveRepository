#include <bits/stdc++.h>
using namespace std;

bool isFound(vector<vector<int>>& matrix, int target){

	bool flag=0;
	int row=0, col=matrix[0].size()-1;
	while(row<matrix.size() && col>=0){
		if(matrix[row][col]==target){
			flag=1;
			break;
		}
		else if(matrix[row][col]<target){
			row++;
		}
		else{
			col--;
		}
	}

	return flag;
}

int main(){

	vector<vector<int>> matrix={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,19,24,28,29}};
	cout << isFound(matrix, 15);

	return 0;
}