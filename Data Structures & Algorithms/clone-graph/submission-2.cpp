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
    unordered_map<Node*,Node*> mp;

    Node* clone(Node* orig){
        if(!orig) return nullptr;
        else if(mp.count(orig)) return mp[orig];

        Node* copy = new Node(orig->val);
        mp[orig] = copy;
        for(Node* kid:orig->neighbors){
            copy->neighbors.push_back(clone(kid));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        return clone(node);
    }
};
