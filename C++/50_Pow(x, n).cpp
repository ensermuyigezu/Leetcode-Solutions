class Solution {
public:
    double myPow(double x, int n) {
        double ans = Pow(x, abs(n));
        if(n < 0) return 1.0/ans;
        else return ans;
    }
    double Pow(double x, int n) {
        if(n == 0) return 1;
        double half = Pow(x, n/2);
        if(n % 2 == 0) return half * half;
        else return x * half * half;
    }
};