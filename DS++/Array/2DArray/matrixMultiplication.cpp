#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiplyMatrices(vector<vector<int>> m1, vector<vector<int>> m2){

	vector<vector<int>> ans;
	for(int i=0; i<m1.size(); i++){
		for(int j=0; j<m2[0].size(); j++){
			for(int k=0; k<m1[0].size(); k++){
				ans[i][j]+=m1[i][k]*m2[k][j];
			}
		}
	}

	return ans;
}

int main(){

	vector<vector<int>> m1, m2;
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			cin >> m1[i][j];
		}
	}
	for(int i=0; i<4; i++){
		for(int j=0; j<3; j++){
			cin >> m2[i][j];
		}
	}

	vector<vector<int>> result;
	result=multiplyMatrices(m1, m2);
	for(int i=0; i<m1.size(); i++){
		for(int j=0; j<m2[0].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}