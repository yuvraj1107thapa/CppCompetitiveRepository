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

// 1 2 3 4 5 6

// 1->2->3->4->5->6->NULL;
// NULL<-1<-2<-3<-4<-5<-6(newHead);
//     1<-2<-3<-4<-5<-6(newHead);
//        2<-3<-4<-5<-6(newHead);
//           3<-4<-5<-6(newHead);
//              4<-5<-6(newHead);
//                 5<-6(newHead);
//                    6(newHead);


Node* reverseRecursive(Node* head){

    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newHead;
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