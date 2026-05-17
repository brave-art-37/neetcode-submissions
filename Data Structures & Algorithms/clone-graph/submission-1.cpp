/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        map<int,Node*> mp;
        set<int> vis;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();q.pop();
            vis.insert(curr->val);
            Node* tmp = new Node(curr->val);
            mp[curr->val] = tmp;
            for(Node* kid:curr->neighbors){
                if(vis.count(kid->val)) continue;
                q.push(kid);
            }
        }
        vis.clear();
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();q.pop();
            Node* curr_copy = mp[curr->val];
            vis.insert(curr->val);
            for(Node* kid:curr->neighbors){
                if(vis.count(kid->val)) continue;
                Node* kid_copy = mp[kid->val];
                curr_copy->neighbors.push_back(kid_copy);
                kid_copy->neighbors.push_back(curr_copy);
                q.push(kid);
            }
        }
        return mp[node->val];
    }
};
