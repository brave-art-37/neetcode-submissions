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
    bool isSame(TreeNode* p, TreeNode* q){
        if(!p && !q) return 1;
        else if(!p || !q) return 0;
        return (p->val==q->val)&&isSame(p->left,q->left)&&isSame(p->right,q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return 1;
        else if(!root && subRoot) return 0;

        return isSame(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};
