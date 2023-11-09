#include <bits/stdc++.h>
using namespace std;

 bool isValid(string s) {
        
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(s[i]==')'){
                    if(!st.empty() && st.top()!='('){
                        return false;
                    }
                    else if(!st.empty()){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                if(s[i]=='}'){
                    if(!st.empty() && st.top()!='{'){
                        return false;
                    }
                    else if(!st.empty()){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                if(s[i]==']'){
                    if(!st.empty() && st.top()!='['){
                        return false;
                    }
                    else if(!st.empty()){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        
        if(!st.empty()){
            return false;
        }
        
        return true;
    }

int main(){
    

    return 0;
}