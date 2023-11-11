#include <iostream>
using namespace std;
int main(){

// Rhombus pattern
//		    * * * * *
//	      * * * * *
//	    * * * * *
//	  * * * * *
//	* * * * *
//	int n;
//	cin >> n;
//	for (int i=1; i<=n; i++){
//		int space = n-i;
//			for (int y=1; y<=space; y++){
//				cout << " " << " ";
//			}
//		for (int j=1; j<=n; j++){
//			cout << "*" << " ";
//		}
//		cout << endl;
//	}

// Number Pattern
//	    1
//	   1 2
//	  1 2 3
//	 1 2 3 4
//	1 2 3 4 5
//	int n;
//	cin >> n;
//	for (int i=1; i<=n; i++){
//		int space=n-i;
//		for (int y=1; y<=space; y++){
//			cout << " ";
//		}
//		for (int j=1; j<=i; j++){
//			cout << j << " ";
//		}
//		for (int y=1; y<=space; y++){
//			cout << " ";
//		}
//		cout << endl;	
//	}

// Pallindromic pattern
//	    1
//	   212
//	  32123
//	 4321234
//	543212345
//	int n;
//	cin >> n;
//	for (int i=1; i<=n; i++){
//		for (int s=1; s<=n-i; s++){
//			cout << " ";
//		}
//		int counter=i;
//		for (int j=1; j<=i; j++){
//			cout << counter;
//			counter--;
//		}
//		counter+=2;
//		for (int k=2; k<=i; k++){
//			cout << counter;
//			counter++;
//		}
//		cout << endl;	
//	}
//	

// Print 0-1 pattern
//  1
//	0 1
//	1 0 1
//	0 1 0 1
//	1 0 1 0 1	
//	int n;
//	cin >> n;
//	for (int i=1; i<=n; i++){
//		for (int j=1; j<=i; j++){
//			if ((i+j)%2==0){
//				cout << "1" << " ";
//			} else {
//				cout << "0" << " ";
//			}
//		}
//		cout << endl;
//	}

// star pattern
//	        *
//	      * * *
//	    * * * * *
//	  * * * * * * *
//	* * * * * * * * *
//	* * * * * * * * *
//	  * * * * * * *
//	    * * * * *
//	      * * *
//	        *
//	int n;
//	cin >> n;
//	for (int i=1; i<=n; i++){
//		for (int s=1; s<=n-i; s++){
//			cout << "  ";
//		}
//		int odd=2*i-1;
//		for (int j=1; j<=odd; j++){
//			cout << "*" << " ";
//		}
//		cout << endl;
//	}
//	for (int i=n; i>=1; i--){
//		for (int s=1; s<=n-i; s++){
//			cout << "  ";
//		}
//		int odd=2*i-1;
//		for (int j=1; j<=odd; j++){
//			cout << "*" << " ";
//		}
//		cout << endl;
//	}

// Pascal Triangle
//      1
//	   1 1
//	  1 2 1
//	 1 3 3 1
//	1 4 6 4 1

//	int n;
//	cin >> n;
//	for (int i=1; i<=n; i++){
//		int coef=1;
//		for (int j=1; j<=n-i; j++){
//			cout << " ";
//		}
//		for (int p=1; p<=i; p++){
//			cout << coef << " ";
//			coef=coef*(i-p)/p;
//		}
//		cout << endl;		
//	}

//	Zig-Zag pattern
//	    *       *
//	  *   *   *   *
//	*       *       *
//	int n;
//	cin >> n;
//	for (int i=1; i<=3; i++){
//		for (int j=1; j<=n; j++){
//			if (( (i+j)%4==0 ) || ( i==2 && j%4==0 )){
//				cout << "* ";
//			}
//			else {
//				cout << "  ";
//			}
//		}
//		cout << endl;
//	}

// hollow rectangle
//	int row, col;
//	cin >> row >> col;
//	for (int i=1; i<=row; i++){
//		for (int j=1; j<=col; j++){
//			if (i==1 || i==row || j==1 || j==col){
//				cout << "*" << " ";
//			} else {
//				cout << " " << " ";
//			}
//		}
//		cout << endl;
//	}

// pyramid pattern
//	*
//	* * 
//	* * * 
//	* * * *
//	* * * * *
// 	int n;
// 	cin >> n;
// 	for (int i=1; i<=n; i++){
// 		for (int j=1; j<=i; j++){
// 			cout << "*" << " ";
//		 }
//		 cout << endl;
//	 }
	 
// pyramid patter 180degree
//		    *
//	      * * 
//	    * * *
//	  * * * * 
//	* * * * *
//	int n;
//	cin >> n;
//	for (int i=1; i<=n; i++){
//		for (int j=1; j<=n; j++){
//			if (j<=n-i) {
//				cout << " " << " ";
//			}
//			else {
//				cout << "*" << " ";
//			}
//		}
//		cout << endl;
//	}

// Number pyramid
//	1
//	2 2
//	3 3 3
//	4 4 4 4
//	5 5 5 5 5
// 	int n;
// 	cin >> n;
// 	for (int i=1; i<=n; i++){
// 		for (int j=1; j<=i; j++){
// 			cout << i << " ";
//		 }
//		 cout << endl;
//	 }
	 
//  Floyd pyramid
//	1
//	2 3
//	4 5 6
//	7 8 9 10
//	11 12 13 14 15
//	int n;
//	cin >> n;
//	int count=1;
// 	for (int i=1; i<=n; i++){
// 		for (int j=1; j<=i; j++){
// 			cout << count << " ";
// 			count++;
//		 }
//		 cout << endl;
//	 }

//  Butterfly pattern
//	*                 *
//	* *             * *
//	* * *         * * *
//	* * * *     * * * *
//	* * * * * * * * * *
//	* * * * * * * * * *
//	* * * *     * * * *
//	* * *         * * *
//	* *             * *
//	*                 *
// int n;
// cin >> n;
// for (int i=1; i<=n; i++){
// 	for (int j=1; j<=i; j++){
// 		if (j<=i){
// 			cout << "*" << " ";
// 		}
// 	}
// 	int space = (n*2)-(i*2);
// 	for (int y=1; y<=space; y++){
// 		cout << " " << " ";
// 	}
// 	for (int j=1; j<=i; j++){
// 		if (j<=i){
// 			cout << "*" << " ";
// 		}
// 	}
// 	cout << endl;
// }
// for (int i=n; i>=1; i--){
// 	for (int j=1; j<=i; j++){
// 		if (j<=i){
// 			cout << "*" << " ";
// 		}
// 	}
// 	int space = (n*2)-(i*2);
// 	for (int y=1; y<=space; y++){
// 		cout << " " << " ";
// 	}
// 	for (int j=1; j<=i; j++){
// 		if (j<=i){
// 			cout << "*" << " ";
// 		}
// 	}
// 	cout << endl;
// }
	
	return 0;
}
