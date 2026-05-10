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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s=to_string(root->val);
        s='('+serialize(root->left)+')'+s+'('+serialize(root->right)+')';
        cout<<s<<"\n";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        string s="";
        int cnt=0, i=0;
        TreeNode* root = new TreeNode();
        for(;i<data.size();i++){
            cnt+=(data[i]=='(')-(data[i]==')');
            if(cnt==0) break;
        }
        root->left = deserialize(data.substr(1,i-1));
        i++;
        while(i<data.size() && data[i]!='(') s+=data[i], i++;
        //cout<<s<<"\n";
        root->right = deserialize(data.substr(i+1,data.size()-i-2));
        root->val = stoi(s);
        return root;
    }
};
