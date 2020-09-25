class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n <= 2) return true;
        int m;
        int b;
        if(coordinates[1][0] - coordinates[0][0] == 0){
            m = INT_MAX;   
        } else {
            m = (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
            b = coordinates[0][1] - m * coordinates[0][0];
        }
        
        for(int i = 2; i < n; i++){
            if(m == INT_MAX){
                if(coordinates[i][0] != coordinates[0][0]) return false;
            } else {
                if(coordinates[i][1] != coordinates[i][0] * m + b) return false; 
            } 
        }
        return true;
    }
};