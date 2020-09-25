class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 31;
        int ans = 0;
        while(i >= 0) {
            int pos = (1<<i);
            if ((m & pos) == (n & pos)) {
                if (m & pos) {
                    ans |= pos;
                }
            } else {
                break;
            }
            i--;
        }
        return ans;
    }
};