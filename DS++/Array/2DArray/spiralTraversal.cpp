#include <bits/stdc++.h>
using namespace std;

void spiralMatrix(vector<vector<int>>& matrix){

	int row_start=0, col_start=0;
	int row_end=matrix.size()-1, col_end=matrix[0].size()-1;

	while(row_start<=row_end && col_start<=col_end){

		//row_start
		for(int i=col_start; i<=col_end; i++){
			cout << matrix[row_start][i] << " ";
		}
		row_start++;

		//col_end
		for(int i=row_start; i<=row_end; i++){
			cout << matrix[i][col_end] << " ";
		}
		col_end--;

		//row_end
		for(int i=col_end; i>=col_start; i--){
			cout << matrix[row_end][i] << " ";
		}
		row_end--;

		//col_start
		for(int i=row_end; i>=row_start; i--){
			cout << matrix[i][col_start] << " ";
		}
		col_start++;

	}

}

int main(){
	
	vector<vector<int>> nums={{1,2,3,4,5},
							 {5,6,7,8,9},
							 {1,2,3,4,5},
							 {5,6,7,8,9},
							 {1,2,3,4,5}};
	spiralMatrix(nums);

	return 0;
}