#include <iostream>
using namespace std;
class Node{
public:
	int val;
	Node* next;	
};

void push(Node* &top, int data){

	Node* t=new Node();
	if(t==NULL){
		cout << "Stack Overflow" << endl;
	}
	else{
		t->val=data;
		t->next=top;
		top=t;
	}
}

int pop(Node* &top){

	int num=-1;
	if(top==NULL){
		cout << "Stack undeflow" << endl;
	}
	else{
		Node* t=top;
		num=top->val;
		top=top->next;
	}

	return num;
}

void display(Node* top){

	Node* temp=top;
	while(top!=NULL){
		cout << top->val << " ";
		top=top->next;
	}
	cout << endl;
}

int peek(Node* top, int pos){

	if(top==NULL){
		return -1;
	}
	else{
		for(int i=0; top!=NULL && i<pos-1; i++){
			top=top->next;
		}
		return top->val;
	}
}

bool isEmpty(Node* top){
	return top?0:1;
}

bool isFull(Node* top){
	Node* n=new Node();
	if(n==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

int Top(Node* top){

	if(top==NULL){
		return -1;
	}
	else{
		return top->val;
	}
}

int main(){
	
	Node* top=NULL;
	push(top, 1);
	push(top, 2);
	push(top, 3);
	display(top);

	cout << peek(top, 2) << endl;

	return 0;
}