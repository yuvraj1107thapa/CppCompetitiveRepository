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
    Node(){
        val=0;
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

Node* partition(Node* head, int k){

    Node* ptr1Head=new Node();
    Node* ptr2Head=new Node();
    Node* ptr1=ptr1Head;
    Node* ptr2=ptr2Head;

    while(head!=NULL){
        if(head->val<k){
            ptr1->next=head;
            ptr1=ptr1->next;
        }
        else{
            ptr2->next=head;
            ptr2=ptr2->next;
        }
        head=head->next;
    }

    ptr2->next=NULL;
    ptr1->next=ptr2Head->next;

    return ptr1Head->next;
}


int main(){
    
    Node* head=new Node(9);
    insert(head, 5, 2);
    insert(head, 3, 3);
    insert(head, 1, 4);
    insert(head, 6, 5);
    insert(head, 7, 6); 
    display(head);
    cout << endl;

    Node* newHead=partition(head, 6);
    display(newHead);


    return 0;
}