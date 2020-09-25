class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1 > n2) return false;
        int i = 0;
        int j = 0;
        int l = n1;
        while(i < n1 && j < n2){
            if(s[i] == t[j]){
                l -= 1;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return l == 0;
    }
};