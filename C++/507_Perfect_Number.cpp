class Solution {
public:
    long pn(int p){
        return (pow(2, p -1) * (pow(2, p) - 1));
    }
    bool checkPerfectNumber(int num) {
        int primes[8] = {2, 3, 5, 7, 13, 17, 19, 31};
        for(int prime : primes){
            if(pn(prime) == num){
                return true;
            }
        }
        return false;
    }
};