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
    void dfs(TreeNode* root, int& cnt, int maxi){
        if(!root) return;
        int newMaxi = max(maxi,root->val);
        cnt+=(newMaxi<=root->val);
        dfs(root->left,cnt,newMaxi);
        dfs(root->right,cnt,newMaxi);
    }

    int goodNodes(TreeNode* root) {
        int good = 0;
        dfs(root,good,INT_MIN);
        return good;
    }
};