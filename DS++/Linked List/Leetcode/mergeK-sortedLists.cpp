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


Node* merge(Node* &head1, Node* &head2){

	Node* dummyNode=new Node(-1);
	Node* ptr=dummyNode;
	while(head1!=NULL && head2!=NULL){
		if(head1->val < head2->val){
			ptr->next=head1;
			head1=head1->next;
		}
		else{
			ptr->next=head2;
			head2=head2->next;
		}
		ptr=ptr->next;
	}
	if(head1!=NULL) ptr->next=head1;
	if(head2!=NULL) ptr->next=head2;
	
	return dummyNode->next;
}

Node* mergeKLists(vector<Node*> lists){

	if(lists.size()==0){
		return NULL;
	}

	int size=lists.size()-1;
	while(size!=0){
		int l=0, r=size-1;
		while(l<r){
			lists[l]=merge(lists[l], lists[r]);
			l++; r--;
			if(l>=r){
				size=r;
				break;
			}
		}
	}
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



	return 0;
}