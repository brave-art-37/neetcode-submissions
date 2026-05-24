class Solution {
public:
    bool valid(int x, int y, int m, int n){
        return (x>-1 && x<m)&&(y>-1 && y<n);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n));
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        //identify comp of Os
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] || board[i][j]=='X') continue;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    int x=q.front().first, y=q.front().second;q.pop();
                    board[x][y]=cnt;
                    for(auto d:dir){
                        int x1=x+d.first, y1=y+d.second;
                        if(!valid(x1,y1,m,n) || vis[x1][y1] || board[x1][y1]!='O') continue;
                        vis[x1][y1]=1;
                        q.push({x1,y1});
                    }
                }
                cnt++;
            }
        }

        //identify comps touch edges
        vector<bool> rep(cnt);
        for(int i=0;i<m;i++){
            if(board[i][0]=='X') continue;
            rep[board[i][0]]=1;
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='X') continue;
            rep[board[i][n-1]]=1;
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='X') continue;
            rep[board[0][j]]=1;
        }
        for(int j=0;j<n;j++){
            if(board[m-1][j]=='X') continue;
            rep[board[m-1][j]]=1;
        }
        
        //replace
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X') continue;
                else if(rep[board[i][j]]==0) board[i][j]='X';
                else if(rep[board[i][j]]==1) board[i][j]='O'; //touch edges
            }
        }
    }
};
