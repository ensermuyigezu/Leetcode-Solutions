class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int begin = 0, end = 0;
        int n = s.size();
        int cost = 0;
        int len = 0;
        for(int i = 0; i < n; i++){
            cost += abs(s[i] - t[i]);
            if(cost == maxCost){
                len = max(len, i - begin + 1);
                cost -= abs(s[begin] - t[begin]);
                begin++;
            } else if(cost > maxCost){
                len = max(len, i - begin);
                cost -= abs(s[begin] - t[begin]);
                begin++;
            } else {
                len = max(len, i - begin + 1);
            }
        }
        return len;
    }
};