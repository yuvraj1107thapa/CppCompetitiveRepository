#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
	int top, size;
	int *S;
};

void create(Stack *st){

	int length;
	cin >> length;
	st->size=length;
	st->top=-1;
	st->S=new int[st->size];
}

void display(Stack st){

	for(int i=st.top; i>=0; i--){
		cout << st.S[i] << " ";
	}
	cout << endl;

}

void push(Stack *st, int val){

	if(st->top==st->size-1){
		cout << "Stack Overflow" << endl;
	}
	else{
		st->top++;
		st->S[st->top]=val;
	}
}

int pop(Stack *st){

	int val=-1;
	if(st->top==-1){
		cout << "Stack Underflow" << endl;
	}
	else{
		int val=st->S[st->top--];
	}

	return val;
}

int peek(Stack st, int pos){

	if(st.top-pos+1<0){
		return -1;
	}
	else{
		return st.S[st.top-pos+1];
	}
}

int stackTop(Stack st){

	if(st.top==-1){
		return -1;
	}
	else{
		return st.S[st.top];
	}
}

bool isEmpty(Stack st){

	if(st.top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

bool isFull(Stack st){

	if(st.top==st.size-1){
		return 1;
	}
	else{
		return 0;
	}
}


int main(){
	
	Stack st;
	create(&st);
	push(&st, 1);
	push(&st, 2);
	push(&st, 3);
	push(&st, 4);
	push(&st, 5);
	push(&st, 6);

	display(st);

	return 0;
}