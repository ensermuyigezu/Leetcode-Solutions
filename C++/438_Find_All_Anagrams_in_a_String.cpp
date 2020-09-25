class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> a;
        int k = p.size();
        vector<int> ans;
        int n = s.size();
        for(char x : p){
            a[x] += 1;
        }
        int counter = a.size();
        for(int i = 0; i < k; i++){
            if(a.find(s[i]) != a.end()){
                a[s[i]]--;
                if(a[s[i]] == 0) counter--;
            }
        }
        if(counter == 0) ans.push_back(0);
        for(int j = 0; j < n; j++){
            if(k >= n) break;
            if(a.find(s[j]) != a.end()){
                if(a[s[j]] == 0) counter++;
                a[s[j]]++;
            }
            if(a.find(s[k]) != a.end()){
                if(a[s[k]] == 1) counter--;
                a[s[k]]--;
            }
            k++;
            if(counter == 0) ans.push_back(j+1);
        }
        return ans;
    }
};