#include <bits/stdc++.h>
using namespace std;

// Idea: Check all the possibilites of arrangement of Queens at board using backtracking,
// 	  For every board[row][col] check if I can place Q and if yes call same function with col+1,
// 	  if col reach end or get greater than col size i.e. means this is one possible arrangement so,
// 	  push that in answer vector and when recursive call done, remove that Q and try other possibilites.

// 	  Check if I can place Q in board[row][col], if there is no Q present at its same col at left part,
// 	  not in left upper diagonal and not not in left downward diagonal. 
// 	  Check only in left part, as I have not cover right part yet because of placing Q col wise.

bool isSafe(vector<string> board, int row, int col, int n){

	for(int i=col; i>=0; i--){
		if(board[row][i]=='Q'){
			return 0;
		}
	}

	int tempRow=row;
	int tempCol=col;
	while(row>=0 && col>=0){
		if(board[row][col]=='Q'){
			return 0;
		}
		row--; col--;
	}

	row=tempRow;
	col=tempCol;
	while(row<n && col>=0){
		if(board[row][col]=='Q'){
			return 0;
		}
		row++; col--;
	}

	return 1;
}

void solve(vector<vector<string>>& ans, vector<string> board, int n, int col){

	if(col>=n){
		ans.push_back(board);
		return;
	}

	for(int row=0; row<n; row++){
		if(isSafe(board, row, col, n)){
			board[row][col]='Q';
			solve(ans, board, n, col+1);
			board[row][col]='.';
		}
	}
}

vector<vector<string>> solveNQueens(int n){

	vector<vector<string>> ans;
	vector<string> board(n);
	string s(n, '.');
	for(int i=0; i<n; i++){
		board[i]=s;
	}
	solve(ans, board, n, 0);

	return ans;
}



//Knight 
void displayBoard(vector<vector<int>> board){

	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[0].size(); j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

bool printKnightMoves(vector<vector<int>>& board, int i, int j, int idx){

	if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]>0){
		return false;
	}
	if(idx>=board.size()*board[0].size()){
		board[i][j]=idx;
		displayBoard(board);
		board[i][j]=0;
		return true;
	}

	board[i][j]=idx;
	if (printKnightMoves(board, i-2, j+1, idx+1)) return true;
	if (printKnightMoves(board, i-1, j+2, idx+1)) return true;
	if (printKnightMoves(board, i+1, j+2, idx+1)) return true;
	if (printKnightMoves(board, i+2, j+1, idx+1)) return true;
	if (printKnightMoves(board, i+2, j-1, idx+1)) return true;
	if (printKnightMoves(board, i+1, j-2, idx+1)) return true;
	if (printKnightMoves(board, i-1, j-2, idx+1)) return true;
	if (printKnightMoves(board, i-2, j-1, idx+1)) return true;
	board[i][j]=0;

	return false;
}



int main(){

	int n;
	cout << "Enter board size: ";
	cin >> n;

	// vector<vector<string>> board;
	// board=solveNQueens(n);
	// for(int i=0; i<board.size(); i++){
	// 	for(int j=0; j<board[0].size(); j++){
	// 		cout << board[i][j];
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }

	vector<vector<int>> board;
	vector<int> row;
	for(int i=0; i<n; i++){
		row.push_back(0);
	}
	for(int i=0; i<n; i++){
		board.push_back(row);
	}
	cout << printKnightMoves(board, 0, 0, 1) << endl;

	return 0;
}