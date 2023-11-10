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

Node* reverse(Node* head){
    
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* prevptr=NULL;
    Node* currptr=head;
    Node* nextptr=NULL;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    
    return prevptr;
}

Node* intersection(Node* head1, Node* head2){

    int l1=len(head1);
    int l2=len(head2);
    int difference=0;

    Node* ptr1=NULL;
    Node* ptr2=NULL;
    if(l1>l2){
        ptr1=head1;
        ptr2=head2;
        difference=l1-l2;
    }
    else{
        ptr1=head2;
        ptr2=head1;
        difference=l2-l1;
    }

    while(difference--){
        if(ptr1==NULL){
            return NULL;
        }
        ptr1=ptr1->next;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        if(ptr1==ptr2){
            return ptr1;
        }
    }

    return NULL;
}

int main(){
    
    Node* head=new Node(9);
    insert(head, 9, 2);
    insert(head, 9, 3);
    insert(head, 9, 4);
    insert(head, 9, 5);
    insert(head, 9, 6); 
    display(head);
    cout << endl;

    return 0;
}