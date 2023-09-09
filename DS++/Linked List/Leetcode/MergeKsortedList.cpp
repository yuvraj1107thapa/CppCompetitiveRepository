// Problem link: https://leetcode.com/problems/merge-k-sorted-lists/

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
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
        
//     }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode();
        ListNode* ans = dummyNode;
        while(l1 and l2) {
            if(l1->val < l2->val) {
                ans->next = l1;
                ans = ans->next;
                l1 = l1->next;
            } else {
                ans->next = l2;
                ans = ans->next;
                l2 = l2->next;
            }
        }
        if(l1) ans->next = l1;
        if(l2) ans->next = l2;
        return dummyNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        int i = 0;
        ListNode* result = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            ListNode* list2 = lists[i];
            result = merge(result, list2);
        }
        return result;
    }
};