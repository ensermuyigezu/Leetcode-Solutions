class Solution {
public:
    int bitwiseComplement(int N) {
        string s = toBinary(N);
        string a;
        for(char &c: s){
            if(c == '1') a += '0';
            else a += '1';
        }
        return toDecimal(a);
    }
    string toBinary(int N){
        if(N == 0) return "0";
        if(N == 1) return "1";
        return toBinary(N / 2) + to_string(N % 2);
    }
    int toDecimal(string s){
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n ; i++){
            if(s[i] == '1') ans += pow(2, n-i-1);
        }
        return ans;
    }
};