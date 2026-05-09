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
    int mpEndHere(TreeNode* root){
        if(!root) return 0;
        return root->val+max({0,mpEndHere(root->left),mpEndHere(root->right)});
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxi=root->val+max(0,mpEndHere(root->left))+max(0,mpEndHere(root->right));
        if(root->left) maxi=max(maxi,maxPathSum(root->left));
        if(root->right) maxi=max(maxi,maxPathSum(root->right));
        return maxi;
    }
};
