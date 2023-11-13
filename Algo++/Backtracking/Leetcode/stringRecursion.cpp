#include <bits/stdc++.h>
using namespace std;

//Reverse string
void reverse(string s){
	if(s.length()==0){
		return;
	}
	
	string ros=s.substr(1);
	reverse(ros);
	cout << s[0];
}

//Move all x to end of string
string moveAllx(string s){
	
	if(s.length()==0){
		return "";
	}
	
	char ch=s[0];
	string ros=s.substr(1);
	string ans=moveAllx(ros);
	if(ch=='x'){
		return ans+ch;
	}
	return ch+ans;
}

//Remove duplicates from string
string removeDup(string s){
	
	if(s.length()==0){
		return "";
	}
	
	char ch=s[0];
	string ans=removeDup(s.substr(1));
	if(ans[0]==ch){
		return ans;
	}
	return ch+ans;
}

//Replace pi with 3.14
void replacePi(string s){
	
	if(s.length()==0){
		return;
	}
	

	if(s[0]=='p' && s[1]=='i'){
		cout << "3.14";
		replacePi(s.substr(2));
	}
	else{
		cout << s[0];
		replacePi(s.substr(1));
	}
}

//Print subsequence
void subseq(string s, string ans){
	
	if(s.length()==0){
		cout << ans << endl;
		return;
	}
	
	char ch=s[0];
	subseq(s.substr(1), ans);
	subseq(s.substr(1), ch+ans);
}

//Tower of Hanoi
void TOH(int n, char src, char dest, char helper){
	
	if(n==0){
		return;
	}
	
	TOH(n-1, src, helper, dest);
	cout << "Move from " << src << " to " << dest << endl;
	TOH(n-1, helper, dest, src);
}

int main(){
	
	TOH(4, 'A', 'B', 'C');
	return 0;
}
