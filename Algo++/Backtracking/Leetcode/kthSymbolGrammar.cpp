#include <bits/stdc++.h>
using namespace std;

int kthSymbolGrammar(int n, int k){

	if(n==1 || k==1) return 0;
	int mid=pow(2, n)/2;
	if(mid<=k){
		return kthSymbolGrammar(n-1, k);
	}
	else{
		return !kthSymbolGrammar(n-1, k-mid);
	}

}

int main(){

	int n, k;
	cin >> n;
	cin >> k;
	cout << kthSymbolGrammar(n, k) << endl;

	return 0;
}