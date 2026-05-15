class Solution {
public:
    struct Point{
        int x, y, cnt;
    };

    vector<vector<bool>> vis;
    vector<pair<int,int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0}, {0,0}};

    bool valid(int x, int y, vector<vector<char>>& board){
        return (x<board.size())&&(y<board[0].size());
    }
    
    bool dfs(vector<vector<char>>& board, string word, Point p, vector<vector<bool>>& vis){
        int x=p.x, y=p.y, cnt=p.cnt;
        if(cnt==word.size()) return 1; //found it
        else if(vis[x][y] || word[cnt]!=board[x][y]) return 0; //letter not match or already used
        int isit=0;
        vis[x][y]=1;
        for(auto d:dir){
            if(valid(x+d.first,y+d.second,board)){
                Point q = Point(x+d.first,y+d.second,cnt+1);
                isit|=dfs(board,word,q,vis);
            }
            if(isit) return 1;
        }
        vis[x][y]=0; //unmark after all futures explored
        return isit;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vis=vector<vector<bool>>(board.size(),vector<bool>(board[0].size()));
        bool isit = 0;
        for(int x=0;x<board.size();x++){
            for(int y=0;y<board[0].size();y++){
                Point p = Point(x,y,0);
                isit|=dfs(board,word,p,vis);

                if(isit) return isit;
            }
        }
        return isit;
    }
};