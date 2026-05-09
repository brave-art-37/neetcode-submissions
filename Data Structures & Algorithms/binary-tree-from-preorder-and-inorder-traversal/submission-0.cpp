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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int idx=0;
        for(int i=0;i<inorder.size();i++) if(inorder[i]==preorder[0]) {idx=i; break;}
        vector<int> fPre, sPre, fIn, sIn;
        for(int i=0;i<inorder.size();i++){
            if(i<idx) fIn.push_back(inorder[i]);
            else if(i>idx) sIn.push_back(inorder[i]);
        }
        for(int i=1;i<preorder.size();i++){
            if(i<idx+1) fPre.push_back(preorder[i]);
            else sPre.push_back(preorder[i]);
        }
        root->left = buildTree(fPre,fIn);
        root->right = buildTree(sPre,sIn);
        return root;
    }
};
