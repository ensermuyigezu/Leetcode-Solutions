class Solution {
public:
    void removeLeadingZeroes(string &num) {
        while(num.length() > 0 && (num.compare(0, 1, "0") == 0)) {
            num.erase(num.begin()+0);
        }
    }
    void removeLeftOver(string &num, int k) {
        int i;
        i = num.length() - k;
        num.erase(num.begin()+i, num.end());
    }
    string removeKdigits(string num, int k) {
        int i = 0;
        while((i < num.length()-1) && (k>0)) { 
            if(num[i] <= num[i+1]){                         
                i++;
            } else {
                num.erase(num.begin()+i);
                k--;
                if(i > 0) i--;
            }
        }
        if(k!=0) removeLeftOver(num, k);
        if(num.compare(0,1,"0") == 0) removeLeadingZeroes(num);
        if(num == "") return "0";
        return num;
    }
};