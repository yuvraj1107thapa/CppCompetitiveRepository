#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
        
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else st.push(s[i]);
            }
        }
        
        return st.size();
    }

int main(){
    
    string str="";
    cout << minAddToMakeValid(str) << endl;

    return 0;
}