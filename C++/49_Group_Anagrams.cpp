class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> d;
        for (string s : strs){
            string t = s;
            sort(s.begin(), s.end());
            d[s].push_back(t);
        }
        vector<vector<string>> l;
        for (auto x : d) {
            l.push_back(x.second);
        }
        return l;
    }
};