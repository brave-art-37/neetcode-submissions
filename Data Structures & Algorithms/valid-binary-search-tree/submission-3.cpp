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
    int giveMax(TreeNode* root){
        if(!root) return INT_MIN;
        while(root->right) root=root->right;
        return root->val;
    }
    int giveMin(TreeNode* root){
        if(!root) return INT_MAX;
        while(root->left) root=root->left;
        return root->val;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return 1;
        bool valid=isValidBST(root->left)&isValidBST(root->right);
        valid &= (giveMax(root->left)<root->val)&(root->val<giveMin(root->right));
        return valid;
    }
};
