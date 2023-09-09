// Problem link: https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int len(ListNode* head){
        
        int length=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        
        return length;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int length=len(head);
        if(length<k){
            return head;
        }
        
        ListNode* prevptr=NULL;
        ListNode* currptr=head;
        ListNode* nextptr;
        int counter=0;
        while(currptr!=NULL && counter<k){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
            counter++;
        }
        
        if(nextptr!=NULL){
            head->next=reverseKGroup(currptr, k);
        }
        
        return prevptr;
    }
};