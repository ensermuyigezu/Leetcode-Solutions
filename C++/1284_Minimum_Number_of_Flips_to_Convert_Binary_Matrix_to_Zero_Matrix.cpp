class Solution {
private:
    int m, n;
    
public:
    int minFlips(vector<vector<int>>& mat) {
        this->m = mat.size();
        this->n = mat[0].size();
        int ans = DFSBacktrack(mat,0,0,0);
        return (ans == INT_MAX)?-1:ans;
    }
    
    void flip(vector<vector<int>>& mat, int i, int j) {
        mat[i][j] ^= 1;                                  
        if(i  > 0) mat[i-1][j] ^= 1;                      
        if(j > 0) mat[i][j-1] ^= 1;
        if(i < m-1) mat[i+1][j] ^= 1;
        if(j < n-1) mat[i][j+1] ^=1;
        return;
    }
    
    bool zeroMat(vector<vector<int>>& mat) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j]) return false;
            }
        }
        return true;
    }
    
    int DFSBacktrack(vector<vector<int>>& mat, int x, int y, int count) {
        if(x == m) {                                
            x = 0;
            y++;
        }
        if(y == n) {
            return zeroMat(mat)?count:INT_MAX;  
        }  
        int path1 = DFSBacktrack(mat,x+1,y,count);                
        flip(mat,x,y);
        int path2 = DFSBacktrack(mat,x+1,y,count+1);           
        flip(mat,x,y);                                          
        return min(path1,path2);                         
    }
};