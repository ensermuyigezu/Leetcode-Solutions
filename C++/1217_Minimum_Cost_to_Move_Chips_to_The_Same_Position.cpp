class Solution {
public:
    int minCostToMoveChips(vector<int>& chips){
        int odd = 0, even = 0;
        int p;
        int minCost = 0;
        for(int x : chips){
            if(x % 2 == 0){
                even++;
            } else {
                odd++;
            }
            if(even > odd){
                p = 0;   
            } else {
                p = 1;
            }
        }
        for(int i = 0; i < chips.size(); i++){
            if(chips[i] % 2 == 1 && p == 0){
                minCost++;
            } else if(chips[i] % 2 == 0 && p == 1){
                minCost++;
            }
        }
        return minCost;
    }
};