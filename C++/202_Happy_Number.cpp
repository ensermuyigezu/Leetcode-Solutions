class Solution {
public:
    bool isHappy(int n) {
        for (int i = 0; i <= 18; i++){
            int x = 0;
            while(n){
                x += pow(n % 10, 2);
                n /= 10;
            }
            n = x;
            if (x == 1) return true;
        }
        return false;
    }
};