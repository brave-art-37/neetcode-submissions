class Solution {
public:
    struct Node{
        bool isWord;
        unordered_map<char,Node*> next;
        Node():isWord(false), next(){};
    };
 
    Node* root;
    vector<int> dp;

    void trieInsert(string& s){
        Node* curr=root;
        for(char c:s){
            if(!curr->next.count(c)){
                Node* tmp  = new Node();
                curr->next[c] = tmp;
            }
            curr = curr->next[c];
        }
        curr->isWord = 1;
    }

    bool helper(string& s, int idx){
        if(idx==s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];
        bool isit=0;
        Node* curr = root;
        for(int i=idx;i<s.size();i++){
            if(!curr->next.count(s[i])) break;
            curr = curr->next[s[i]];
            if(curr->isWord) dp[i+1]=helper(s,i+1), isit|=dp[i+1];
            if(isit) break;
        }
        dp[idx] = isit;
        return isit;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<int>(s.size()+1,-1);
        root = new Node();
        for(string t:wordDict){
            //if(helper(t,0)) continue;
            trieInsert(t);
        }
        return helper(s,0);
    }
};