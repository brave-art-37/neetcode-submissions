class WordDictionary {
public:
    struct Node{
        bool isWord;
        vector<Node*> next;

        Node():isWord(0),next(26,nullptr){}
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char c:word){
            if(!curr->next[c-'a']){
                Node* tmp = new Node();
                curr->next[c-'a'] = tmp;
            }
            curr = curr->next[c-'a'];
        }
        curr->isWord = 1;
    }

    bool searchHelper(string word, int idx, Node* start){
        if(idx==word.size()) return start->isWord;
        Node* curr = start;
        for(int i=idx;i<word.size();i++){
            char c = word[i];
            if(c=='.') {
                bool isit=0;
                for(int j=0;j<26;j++){
                    if(!curr->next[j]) continue;
                    isit|=searchHelper(word,i+1,curr->next[j]);
                    if(isit) return 1;
                }
                return 0;
            }
            else if(!curr->next[c-'a']) return 0;
            curr = curr->next[c-'a'];
        }
        return curr->isWord;
    }
    
    bool search(string word) {
        return searchHelper(word,0,root);
    }
};
