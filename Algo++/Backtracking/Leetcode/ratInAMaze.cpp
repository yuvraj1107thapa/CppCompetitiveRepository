#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>& ans, string st, int row, int col, vector<vector<int>>& m, int n){
    
    if(row==n-1 && col==n-1){
        ans.push_back(st);
        return;
    }
        
    //Right
    if(col+1<n && m[row][col+1]==1){
        st+='R';
        m[row][col]=-1;
        solve(ans, st, row, col+1, m, n);
        st.pop_back();
        m[row][col]=1;
    }
    //Down
    if(row+1<n && m[row+1][col]==1){
        st+='D';
        m[row][col]=-1;
        solve(ans, st, row+1, col, m, n);
        st.pop_back();
        m[row][col]=1;
    }
    //Left
    if(col-1>=0 && m[row][col-1]==1){
        st+='L';
        m[row][col]=-1;
        solve(ans, st, row, col-1, m, n);
        st.pop_back();
        m[row][col]=1;
    }
    //Up
    if(row-1>=0 && m[row-1][col]==1){
        st+='U';
        m[row][col]=-1;
        solve(ans, st, row-1, col, m, n);
        st.pop_back();
        m[row][col]=1;
    }

}

vector<string> findPath(vector<vector<int>> &m, int n) {

    vector<string> ans;
    if(m[0][0]==0){
        ans.push_back(to_string(-1));
        return ans;
    }
    string st="";
    solve(ans, st, 0, 0, m, n);
    if(ans.size()==0){
        ans.push_back(to_string(-1));
        return ans;
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    vector<vector<int>> m;
    vector<int> path(n);

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> path[j];
        }
        m.push_back(path);
    }
    vector<string> ans;
    ans=findPath(m, n);
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}