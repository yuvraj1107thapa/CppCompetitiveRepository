#include <bits/stdc++.h>
using namespace std;

class node{
public:
	node* next[26];
	string str;
	node(){
		for(int i=0; i<26; i++){
			next[i]=NULL;
		}
		str="";
	}

};



void insert(node* root, string word){
	node* temp=root;
	for(auto ch: word){
		if(temp->next[ch-'a']==NULL){
			temp->next[ch-'a']=new node();
		}
		temp=temp->next[ch-'a'];
	}
	temp->str=word;
}



void dfs(vector<vector<char>>& board, vector<string>& ans, int i, int j, node* root){

	if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;

	char ch=board[i][j];
	if(ch=='/') return;
	if(root->next[ch-'a']==NULL) return;
	root=root->next[ch-'a'];
	if(root->str!=""){
		ans.push_back(root->str);
		root->str="";
	}


	board[i][j]='/';
	dfs(board, ans, i+1, j, root);
	dfs(board, ans, i-1, j, root);
	dfs(board, ans, i, j+1, root);
	dfs(board, ans, i, j-1, root);
	board[i][j]=ch;
}



vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
	
	vector<string>ans;
	node* root=new node();
	for(auto i: words){
		insert(root, i);
	}	

	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[0].size(); j++){
			char ch=board[i][j];
			if(root->next[ch-'a']!=NULL){
				dfs(board, ans, i, j, root);
			}
		}

	}

	return ans;
}



int main(){
	
	vector<vector<char>> board={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
	vector<string> words={"oath","pea","eat","rain"};
	vector<string> ans=findWords(board, words);
	for(auto i: ans){
		cout << i << endl;
	}
	
	return 0;
}