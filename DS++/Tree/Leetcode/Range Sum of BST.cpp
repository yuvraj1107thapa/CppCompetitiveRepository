/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum(TreeNode* root, int st, int end) {
        if(root==NULL) return 0;
        int left=sum(root->left, st, end);
        int right=sum(root->right, st, end);
        if(root->val>=st and root->val<=end) {
            return root->val+left+right;
        }
        return left+right;
    }
    int rangeSumBST(TreeNode* root, int st, int end) {
        int result=sum(root,st,end);
        return result;
    }
};