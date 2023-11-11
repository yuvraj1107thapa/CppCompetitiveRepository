#include <iostream>
using namespace std;

class Diagonal{
private:
	int n;
	int *matrix;
public:
	Diagonal(int n);
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
	~Diagonal(){
		delete []matrix;
	}
};

Diagonal::Diagonal(int n){
	this->n=n;
	matrix=new int[n];
}
void Diagonal::set(int i, int j, int x){
	if(i==j){
		matrix[i-1]=x;
	}
}
int Diagonal::get(int i, int j){
	if(i==j){
		return matrix[i-1];
	}
	else{
		return 0;
	}
}
void Diagonal::display(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j){
				cout << matrix[i] << " ";
			}
			else{ 
				cout << "0 ";
			}
		}
		cout << endl;
	}
}

int main(){

	Diagonal matrix(5);
	matrix.set(1,1,1);
	matrix.set(2,2,2);
	matrix.set(3,3,3);
	matrix.set(4,4,4);
	matrix.set(5,5,5);
	matrix.display();

	return 0;
}
