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
//return N
//ptr N
//infLoop N
//idxErr N
//oneOff N
//edgeVals N
    vector<vector<int>> levelOrder(TreeNode* root){
        if(!root) return vector<vector<int>>();

        vector<vector<int>> v1,v2,v;
        v1 = levelOrder(root->right);
        v2 = levelOrder(root->left);
        int m=v1.size(), n=v2.size();
        v.push_back(vector<int>(1,root->val));
        for(int i=0;i<min(m,n);i++){
            v1[i].insert(v1[i].end(),v2[i].begin(),v2[i].end());
            v.push_back(v1[i]);
        }
        for(int i=min(m,n);i<max(m,n);i++){
            if(i<m) v.push_back(v1[i]);
            if(i<n) v.push_back(v2[i]);
        }
        return v;
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>();
        vector<vector<int>> v=levelOrder(root);
        vector<int> rVu;
        for(auto &it:v) if(!it.empty()) rVu.push_back(it[0]);
        return rVu;
    }
};