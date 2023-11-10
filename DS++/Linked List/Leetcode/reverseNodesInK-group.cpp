#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	int val;
	Node* next;
	Node(int data){
		val=data;
		next=NULL;
	}
};

void insert(Node* &head, int data, int pos){

	if(pos==1){
		Node* node=new Node(data);
		node->next=head;
		head=node;
		return;
	}

	Node* temp=head;
	int count=1;
	while(temp!=NULL){
		if(count==pos-1){
			Node* node=new Node(data);
			node->next=temp->next;
			temp->next=node;
			break;
		}
		temp=temp->next;
		count++;
	}
}
void display(Node* head){

	Node* temp=head;
	while(temp!=NULL){
		cout << temp->val << " ";
		temp=temp->next;
	}
}


int len(Node* head){

	int length=0;
	Node* temp=head;
	while(temp!=NULL){
		temp=temp->next;
		length++;
	}

	return length;
}


 
//Reverse Nodes In K Group Size
Node* reverseKNodes(Node* head, int k){

	int length=len(head);
	if(length<k){
		return head;
	}

	int count=0;
	Node* prevptr=NULL;
	Node* currptr=head;
	Node* nextptr;
	while(currptr!=NULL && count<k){
		nextptr=currptr->next;
		currptr->next=prevptr;
		prevptr=currptr;
		currptr=nextptr;
		count++;
	}

	if(nextptr!=NULL){
		head->next=reverseKNodes(currptr, k);
	}

	return prevptr;
}


int main(){
	
	Node* head=new Node(1);
	insert(head, 2, 2);
	insert(head, 3, 3);
	insert(head, 4, 4);
	insert(head, 5, 5);
	insert(head, 6, 6);	
	display(head);
	cout << endl;

	Node* newHead=reverseKNodes(head, 5);
	display(newHead);
	cout << endl;


	return 0;
}