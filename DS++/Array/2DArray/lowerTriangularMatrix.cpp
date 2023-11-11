#include <iostream>
using namespace std;

class lowerTriangular{
private:
	int n;
	int *matrix;
public:
	lowerTriangular(int n);
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
	~lowerTriangular(){
		delete []matrix;
	}
};

lowerTriangular::lowerTriangular(int n){
	this->n=n;
	matrix=new int[(n*(n+1))/2];
}
void lowerTriangular::set(int i, int j, int x){
	if(i>=j){
		matrix[i*i-1/2+j-1]=x;
	}
}
int lowerTriangular::get(int i, int j){
	if(i>=j){
		//i=i-1;
		//i=i*(i-1)/2;
		//j=j-1;
		return matrix[i*(i-1)/2+j-1];
	}
	return 0;
}
void lowerTriangular::display(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i>=j){
				cout << matrix[i*(i-1)/2+j-1] << " ";
			}	
			else{		
				cout << "0 ";
			}
		}
		cout << endl;
	}
}

int main(){

	int n;
	cout << "Enter dimensions: ";
	cin >> n;
	lowerTriangular lm(n);
	cout << "Enter all elements: " << endl;
	int val;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> val;
			lm.set(i,j,val);
		}
	} 
	lm.display();
	
	return 0;
}
