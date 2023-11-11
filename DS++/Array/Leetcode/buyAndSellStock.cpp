#include <bits/stdc++.h>
using namespace std;
 
//Max profit from buy and sell stock with one transaction
int maxProfit(vector<int> &prices){

	int minPrice=INT_MAX;
	int profit=0;
	for(int i=0; i<prices.size(); i++){
		minPrice=min(minPrice, prices[i]);
		profit=max(profit, prices[i]-minPrice);
	}

	return profit;
}

//Max profit from buy and sell stock with multiple transaction
int maxProfit2(vector<int> &prices){

	int profit=0;
	for(int i=1; i<prices.size(); i++){
		if(prices[i]>prices[i-1]){
			profit+=prices[i]-prices[i-1];
		}
	}

	return profit;
}

int main(){	

	vector<int> prices={7,1,5,3,6,4};
	cout << maxProfit2(prices) << endl;

	return 0;
}