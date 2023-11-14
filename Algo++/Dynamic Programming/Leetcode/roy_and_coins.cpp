#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	std::cin>>n;
	int m;
	std::cin>>m;
	vector<int> prefix(n+1, 0);
	for(int i=0; i<m; i++){
		int l,r;
		std::cin>>l>>r;
		prefix[l]++;
		if(r+1<=n){	
			prefix[r+1]-=1;
		}
	}
	for(int i=1; i<=n; i++){
		prefix[i]+=prefix[i-1];
	}

	vector<long long> freq(100005,0);
	for(int i=0; i<=n; i++){
		freq[prefix[i]]+=1;
	}
	//suffix 
	for(int i=freq.size()-2; i>=0; i--){
		freq[i]=freq[i]+freq[i+1]; 
	}

	int Q;
	std::cin>>Q;
	while(Q--){
		int num;
		std::cin>>num;
		cout<<freq[num]<<endl;
	}

	return 0;
}