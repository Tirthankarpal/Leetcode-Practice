class Solution {
    int num=0;
    public boolean isSafe(char[][] board,int row,int col){
        //check row
        for(int l=0;l<board[0].length;l++){
            if(board[row][l]=='Q')return false;
        }
        for(int l=0;l<board.length;l++){
            if(board[l][col]=='Q')return false;
        }
        //check north-east
        int i=row;
        int j=col;
        while(i>=0&&j<board[0].length){
            if(board[i][j]=='Q')return false;
            i--;
            j++;
        }
        //north-west
        i=row;
        j=col;
        while(i>=0&&j>=0) {
            if (board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        //south east
        i=row;
        j=col;
        while(i<board.length&&j<board[0].length){
            if(board[i][j]=='Q')return false;
            i++;
            j++;
        }
        i=row;
        j=col;
        //south-west
        while(i<board.length&&j>=0){
            if(board[i][j]=='Q')return false;
            i++;
            j--;
        }
        return true;
    }
    public void nqueen(char[][] board,int row){
        int n=board.length;
        if(row==n){
            num++;
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j)){
                board[row][j]='Q';
                nqueen(board,row+1);
                board[row][j]='.';//backtracking
            }
        }
    }
    public int totalNQueens(int n) {
        char[][] board=new char[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j]='.';
            }
        }
        nqueen(board,0);
        return num;
    }
}