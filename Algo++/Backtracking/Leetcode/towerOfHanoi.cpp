#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char helper){

	if(n==0){
		return;
	}

	towerOfHanoi(n-1, source, helper, destination);
	cout << "Move from " << source << " to " << destination;
	towerOfHanoi(n-1, destination, helper, source);

}

int main(){

	towerOfHanoi(3, 'I', 'J', 'K');

	return 0;
}