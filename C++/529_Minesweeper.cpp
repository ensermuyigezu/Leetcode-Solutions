class Solution {
    void dfs(vector<vector<char>>& board, int x, int y){
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) 
            return;
        if(board[x][y] != 'E') 
            return;  
        int count = 0;
        for(int i = -1; i < 2; i++)
            for(int j = -1; j < 2; j++)
                if(x+i >= 0 && y+j >= 0 && x+i < board.size() && y+j < board[0].size())
                    if(board[x+i][y+j] == 'M') 
                        count++;
        if(count){
            board[x][y] = '0' + count;
            return;
        }
        board[x][y] = 'B';
        // left, right, down, up
        dfs(board, x-1, y);
        dfs(board, x+1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);
        // diagonals
        dfs(board, x-1, y-1);
        dfs(board, x+1, y+1);
        dfs(board, x+1, y-1);
        dfs(board, x-1, y+1);
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return board;
        }
        dfs(board, x, y);
        return board;
    }
};