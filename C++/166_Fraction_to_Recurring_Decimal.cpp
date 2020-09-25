class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 1) return to_string(numerator);
        if(numerator == -2147483648 && denominator == -1) {
            return "2147483648";
        }
        unordered_map<int, int> mp; 
        string res;
        if(((numerator < 0) ^ (denominator < 0)) && numerator != 0 ){
            res += "-";
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        long rem = numerator % denominator;
        res += to_string(numerator / denominator);
        if(rem != 0) res += ".";
        while((rem != 0) && (mp.find(rem) == mp.end())){ 
            mp[rem] = res.length();
            rem = rem * 10;
            res += to_string(rem / denominator);
            rem = rem % denominator;
        }
        return (rem == 0) ? res :  res.substr(0, mp[rem]) + "(" + res.substr(mp[rem]) + ")";
    }
};