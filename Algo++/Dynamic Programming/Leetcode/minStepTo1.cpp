#include <bits/stdc++.h>
using namespace std;
#define inf 100005

int dp[100005];
long long f(int n){
	

	if(n==1) return 0; //base case
	if(n==2) return 1; //base case
	if(n==3) return 1; //base case
	if(dp[n]!=-1) return dp[n]; //if already it's pre-computed so return the value

	long long ans=inf;//initially initialize ans as infinity
	if(n%2==0) ans=min(ans, f(n/2)); //if divisible by 2, update ans
	if(n%3==0) ans=min(ans, f(n/3)); //if divisible by 3, update ans
	ans=min(ans, f(n-1)); //update ans

	if(ans==inf) return dp[n]=ans; //if ans still infinity, update dp[n] and return infinity
	return dp[n]=1+ans; //update dp[n], add 1 to ans and return updated value of dp[n]
}

long long fTopDownDP(int n){

	vector<int> dp1(n+1, -1);
	dp1[1]=0;
	dp1[2]=dp1[3]=1;
	for(int i=4; i<=n; i++){
		dp1[i]=dp1[i-1];
		if(i%2==0){
			dp1[i]=min(dp1[i], dp1[i/2]);
		}
		if(i%3==0){
			dp1[i]=min(dp1[i], dp1[i/3]);
		}
		dp1[i]+=1;
	}

	return dp1[n];
}

int main(){
	
	std::memset(dp, -1, sizeof dp); //initialize global array dp[]={-1};
	long long ans=fTopDownDP(10);
	cout << ans << endl;

	return 0;
}