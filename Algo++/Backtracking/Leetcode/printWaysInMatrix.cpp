#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& ans, vector<int> ds, vector<vector<int>> board, int i, int j){

	if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]==-1){
		return;
	}

	if(i==board.size()-1 && j==board[0].size()-1){
		ds.push_back(board[i][j]);
		ans.push_back(ds);
		ds.pop_back();
		return;
	}

	ds.push_back(board[i][j]);
	dfs(ans, ds, board, i, j+1);
	ds.pop_back();

	ds.push_back(board[i][j]);
	dfs(ans, ds, board, i+1, j);
	ds.pop_back();
}

int main(){
	
	vector<vector<int>> board={{1,2,3},
							   {4,5,6},
							   {7,8,9}};
	vector<int> ds;
	vector<vector<int>> ans;
	dfs(ans, ds, board, 0, 0);

	for(auto i: ans){
		for(auto j: i){
			cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}