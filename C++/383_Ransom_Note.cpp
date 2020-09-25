class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> a;
        for(char &c : ransomNote){
            a[c]++;
        }
        for(char &c : magazine){
            if(a.count(c) == 1 && a[c] == 1){
                a.erase(c);
            } else if(a.count(c) == 1 && a[c] > 0){
                a[c]--;
            }
        }
        return a.empty();
    }
};