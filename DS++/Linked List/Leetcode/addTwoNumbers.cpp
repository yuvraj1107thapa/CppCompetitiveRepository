// Problem link: https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =  0;
        ListNode* dummyNode = new ListNode();
        ListNode* ans = dummyNode;
        while(l1 or l2 or carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            if(sum < 10) {
                ListNode* temp = new ListNode(sum);
                ans->next = temp;
                ans = ans->next;
                carry = 0;
            } else {
                ListNode* temp = new ListNode(sum % 10);
                ans->next = temp;
                ans = ans->next;
                carry = sum / 10;
            }
            l1 ? l1 = l1->next : NULL;
            l2 ? l2 = l2->next : NULL;
        }
        return dummyNode->next;
    }
};