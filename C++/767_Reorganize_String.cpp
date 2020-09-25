class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        vector<int> counts(26);
        for(char c : S) counts[c - 'a'] += 100;
        for(int i = 0; i < 26; ++i) counts[i] += i;
        sort(counts.begin(), counts.end());
        vector<char> ans(n);
        string s;
        int t = 1;
        for(int code : counts){
            int ct = code / 100;
            char ch = 'a' + (code % 100);
            if(ct > (n+1) / 2) return "";
            for(int i = 0; i < ct; ++i){
                if(t >= n) t = 0;
                ans[t] = ch;
                t += 2;
            }
        }
        for(char c : ans) s += c;
        return s;
    }
};