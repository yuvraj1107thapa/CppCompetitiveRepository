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

Node* removeNthNode(Node* head, int k){

    int length=len(head);
    if(length==n){
        Node* todelete=head;
        head=head->next;
        delete todelete;
        return head;
    }

    Node* temp=head;
    int count=1;
    while(head!=NULL){
        if(count==length-k){
            if(temp->next!=NULL){
                Node* todelete=temp->next;
                temp->next=temp->next->next;
                delete todelete;
                return head;
            }
        }
        temp=temp->next;
        count++;
    }

    return head;
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

    Node* newHead=addOne(head);
    display(newHead);
    cout << endl;
    return 0;
}