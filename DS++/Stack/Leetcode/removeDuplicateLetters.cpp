#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
        
        vector<bool> exist(26, false);
        vector<int> count(26);
        for(int i=0; i<s.size(); i++){
            count[s[i]-'a']++;
        }
        
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            char ch=s[i];
            count[ch-'a']--;
            if(exist[ch-'a']){
                continue;
            }
            while(!st.empty() && st.top()>ch && count[st.top()-'a']>0){
                    char temp=st.top();
                    st.pop();
                    exist[temp-'a']=false;
            }
            st.push(ch);
            exist[ch-'a']=true;
        }
        
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;
    }

int main(){
            
    string str;
    getline(cin, str);
    string ans=removeDuplicateLetters(str);
    cout << ans << endl;

    return 0;
}