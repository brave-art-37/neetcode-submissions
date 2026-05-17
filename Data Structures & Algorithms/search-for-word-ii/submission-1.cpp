class Solution {
public:

    struct Node{
        bool isWord;
        string val;
        vector<Node*> next;
        Node():isWord(0),val(""),next(26,nullptr){}
    };

    struct Trie{
        Node* root;
        Trie(){
            root = new Node();
        }
        void addWord(string word){
            Node* curr = root;
            for(char c:word){
                if(!curr->next[c-'a']){
                    Node* tmp = new Node();
                    tmp->val = curr->val+c;
                    curr->next[c-'a'] = tmp;
                }
                curr = curr->next[c-'a'];
            }
            curr->isWord = 1;
        }
    };

    struct Point{
        int x, y;
        Point(int x, int y):x(x),y(y){}
    };

    vector<vector<bool>> vis;
    vector<pair<int,int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0}};
    set<string> res;

    bool valid(int x, int y, vector<vector<char>>& board){
        return (x>-1 && x<board.size())&&(y>-1 && y<board[0].size());
    }


    void dfs(Point p, Node* curr, vector<vector<char>>& board){
        if(vis[p.x][p.y]) return; //already used
        else if(curr->isWord) res.insert(curr->val); //got a word
        
        vis[p.x][p.y] = 1; //choose
        for(auto d:dir){
            int x1=p.x+d.first, y1=p.y+d.second;
            if(!valid(x1,y1,board)) continue; //out of board
            char c = board[x1][y1];
            if(!curr->next[c-'a']) continue; //not in trie
            Point q = Point(x1,y1);
            dfs(q,curr->next[c-'a'],board); //explore
        }
        vis[p.x][p.y] = 0; //unchoose
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        for(string word:words) trie->addWord(word);
        int m=board.size(), n=board[0].size();
        vis = vector<vector<bool>>(m,vector<bool>(n));
        res = set<string>();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char c = board[i][j];
                if(!trie->root->next[c-'a']) continue; //not in trie
                Point p = Point(i,j);
                dfs(p,trie->root->next[c-'a'],board);
            }
        }
        vector<string> ans;
        for(auto& s:res) ans.push_back(s);
        return ans;
    }
};
