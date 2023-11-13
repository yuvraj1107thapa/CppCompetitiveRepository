#include <iostream>
using namespace std;

// Power of n
int power(int n, int p){
	if (p==0){
		return 1;
	}
	return n*power(n, p-1);
}

// Sum till n
int sum(int n){
	if (n==0){
		return 0;
	}
	return n+sum(n-1);
}

// Factorial of n
int factorial(int n){
	if (n==0){
		return 1;
	}
	return n*factorial(n-1);
}

// Fibonnaci number of n
int fibo(int n){
	if (n==0 || n==1){
		return n;
	}
	return fibo(n-1) + fibo(n-2);
}

// Vector is sorted or not
bool sorted (int nums[], int n){
	if (n==1){
		return true;
	}
	int restNums=sorted(arr+1, n-1);
//	return (nums[0]>nums[1] && restNums);
	if (nums[0]>nums[1] && restNums){
		return true;
	}
	return false;	
}

void decrease(int n){
	if (n==1){
		cout << "1" << endl;
		return;
	}
	cout << n << " ";
	decrease(n-1);
}

void increase(int n){
	if (n==1){
		cout << "1" << " ";
		return;
	}
	increase(n-1);
	cout << n << " ";
	return;
}

int firstOccur(int nums[], int n, int i, int key){
//	i=0 n=6 key=2
	if (i==n){
		return -1;
	}
	if (nums[i]==key){
		return i;
	}
	return firstOccur(nums,n,i+1,key);
}

int lastOccur(int nums[], int n, int i, int key){
	if (i==n){
		return -1;
	}
	int restNums=lastOccur(nums, n, i+1, key);
	if (restNums!=-1){
		return restNums;
	}
	if (nums[i]==key){
		return i;
	}
	return -1;
}
int main(){
//	cout << "4 power 3 is ";
//	cout << power(4,3) << endl;
//	cout << "Sum of 5 is ";
//	cout << sum(5) << endl;
//	cout << "Factorial of 5 is ";
//	cout << factorial(5) << endl;
//	cout << "Fibonacci of 5 is ";
//	cout << fibo(5) << endl;
//	int arr[]={1,2,3,4,5,6};
//	cout << "Array is sorted : "
//	cout << sorted(arr, 5);
//	int n;
//	cin >> n;
//	cout << "Increase element till n is ";
//	increase(n);
//	cout << endl;
//	cout << "Decrease elements from n is ";
//	decrease(n);
	int arr[]={1,2,4,2,4,2,7};
	cout << "The elements of array is ";
	for (int i=0; i<7; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "The index of first occurence in given array is ";
	cout << firstOccur(arr,7,0,2) << endl;
	cout << "The index of last occurence in given array is ";
	cout << lastOccur(arr,7,0,2) << endl;
	return 0;
}
