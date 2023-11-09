#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
        
        stack<int> openBracket;
        stack<int> asterisk;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                openBracket.push(i);
            }
            else if(s[i]=='*'){
                asterisk.push(i);
            }
            else if(s[i]==')'){
                if(!openBracket.empty()){
                    openBracket.pop();
                }
                else if(!asterisk.empty()){
                    asterisk.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        while(!openBracket.empty() && !asterisk.empty()){
            if(openBracket.top() > asterisk.top()){
                return false;
            }
            openBracket.pop(); 
            asterisk.pop();
        }
     
        if(!openBracket.empty()){
            return false;
        }
        
        return true;
    }

int main(){
	
	string str;
	getline(cin, str);

	if(checkValidString(str)){
		cout << "String have valid parentheses" << endl;
	}
	else{
		cout << "String have invalid parentheses" << endl;
	}
	
	return 0;
}