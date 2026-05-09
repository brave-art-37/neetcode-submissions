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
    int subtreeSize(TreeNode* root){
        if(!root) return 0;
        return 1+subtreeSize(root->left)+subtreeSize(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int rank = subtreeSize(root) - subtreeSize(root->right);

        if(k==rank) return root->val;
        else if(k<rank) return kthSmallest(root->left,k);
        else if(k>rank) return kthSmallest(root->right,k-rank);
    }
};
