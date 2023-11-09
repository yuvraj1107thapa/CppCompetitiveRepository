#include <bits/stdc++.h>
using namespace std;

 string reverseParentheses(string s) {
        
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')'){
                string str="";
                while(!st.empty() && st.top()!='('){
                    str+=st.top();
                    st.pop();
                }
                st.pop();
                
                for(int j=0; j<str.size(); j++){
                    st.push(str[j]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;
    }

int main(){

    string str="";
    string ans=reverseParentheses(str);
    cout << ans << endl;


    return 0;
}