class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> j;
        int ans = 0;
        for(char c : J) j.insert(c);
        for(char c : S){
            if(j.count(c) == 1) ans++;
        }
        return ans;
    }
};