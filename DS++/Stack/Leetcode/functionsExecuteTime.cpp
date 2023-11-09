#include <bits/stdc++.h>
using namespace std;
class pair{
public:
	int id;
	int startTime;
	int childTime;
}

vector<int> exclusiveTime(int n, vector<string> logs){
	
	vector<int> ans(n, 0);
	stack<pair> st;
	for(auto i: logs){
		vector<string> log;
		string s="";
		for(int j=0; j<i.size(); j++){
			s+=i[j];
			if(i[j]==':' || j==s.size()-1){
				if(j!=s.size()-1){
					s.pop_back();
				}
				log.push_back(s);
				s="";
			}
		}
		if(log[1].compare("start")==0){
			pair p;
			p.id=stoi(log[0]);
			p.startTime=stoi(log[2]);
			p.childTime=0;
			st.push_back(p);
		}
		else{
			pair p=st.top();
			st.pop();
			int interval=stoi(log[2])-p.startTime+1;
			int time=interval-p.childTime;
			st.id+=time;
			if(st.size()>0){
				st.top().childTime+=interval;
			}
		}

	}

	return ans;
}

int main(){
	


	return 0;
}