#include <bits/stdc++.h>
using namespace std;

vector<int> onlineStockSpan(vector<int> price){

	vector<int> ans;
	stack<pair<int, int>> st;
	for(int i=0; i<price.size(); i++){
		int days=1;
		while(!st.empty() && st.top().first<=price[i]){
			days+=st.top().second;
			st.pop();
		}
		st.push({price[i], days});
		ans.push_back(days);
	}

	return ans;
}

int main(){
	
	vector<int> price={10,5,7,6,1,2,3,7};
	vector<int> span=onlineStockSpan(price);
	for(auto i: span){
		cout << i << " ";
	}
	cout << endl;

	return 0;
}