class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> a;
        unordered_map<char, int> b;
        for(char c : s){
            a[c]++;
        }
        for(char c : t){
            b[c]++;
        }
        return a == b;
    }
};