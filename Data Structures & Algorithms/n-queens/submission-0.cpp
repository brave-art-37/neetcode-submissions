class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;
    vector<bool> diag1, diag2, rows, cols;

    void recurr(int row, int n){
        if(row==n){
            res.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(rows[row] || cols[col] || diag1[row+col] || diag2[row-col+n-1]) continue;
            rows[row]=1; cols[col]=1;
            diag1[row+col]=1; diag2[row-col+n-1]=1;
            board[row][col]='Q';
            recurr(row+1,n);
            rows[row]=0; cols[col]=0;
            diag1[row+col]=0; diag2[row-col+n-1]=0;
            board[row][col]='.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n,string(n,'.'));
        diag1 = vector<bool>(2*n-1,0);
        diag2 = vector<bool>(2*n-1,0);
        rows = vector<bool>(n,0);
        cols = vector<bool>(n,0);
        recurr(0,n);
        return res;
    }
};
