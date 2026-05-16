class PrefixTree {
public:
    struct Node{
        bool isWord;
        vector<Node*> next;
        Node():isWord(0),next(26,nullptr){};
    };

    Node* root;

    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr=root;
        for(char c:word){
            if(!curr->next[c-'a']){
                Node* tmp = new Node();
                curr->next[c-'a'] = tmp;
            }
            curr = curr->next[c-'a'];
        }
        curr->isWord = 1;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char c:word){
            if(!curr->next[c-'a']) return 0;
            curr = curr->next[c-'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string word) {
        Node* curr = root;
        for(char c:word){
            if(!curr->next[c-'a']) return 0;
            curr = curr->next[c-'a'];
        }
        return 1;
    }
};
