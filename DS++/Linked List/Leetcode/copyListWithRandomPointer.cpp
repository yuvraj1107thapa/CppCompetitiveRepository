// Problem link: https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        // Adding one alternative copy node
        Node* ptr = head;
        while(ptr != NULL) {
            Node* temp = new Node(ptr->val);
            temp->next = ptr->next;
            ptr->next = temp;
            ptr = ptr->next->next;
        }
        
        // Making copy node random connection as original
        ptr = head;
        while(ptr != NULL) {
            if(ptr->random != NULL) {
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }
        
        // Seperating copy node list from original list
        ptr = head;
        Node* dummyNode = new Node(0);
        Node* helper = dummyNode;
        while(ptr != NULL) {
            helper->next = ptr->next;
            helper = helper->next;
            ptr->next = ptr->next->next;
            ptr = ptr->next;
        }
        
        return dummyNode->next;
    }
};