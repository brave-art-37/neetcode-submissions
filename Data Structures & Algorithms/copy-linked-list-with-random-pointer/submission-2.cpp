/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* orig = head;
        Node dummy(0);
        Node* curr = &dummy;

        //zig zag
        while(orig){
            Node* copy = new Node(orig->val);
            curr->next = orig;
            Node* next = orig->next;
            orig->next = copy;
            orig = next; 
            curr = copy;
        }

        //random deepcopy
        orig = head;
        while(orig){
            Node* copy = orig->next;
            copy->random = (orig->random)?orig->random->next:nullptr;
            orig = copy->next;
        }

        dummy.next = head->next;
        orig = head;
        while(orig){
            Node* copy = orig->next;
            orig->next = copy->next;
            copy->next = (copy->next)?(copy->next->next):nullptr;
            orig = orig->next;
        }
        return dummy.next;
    }
};
