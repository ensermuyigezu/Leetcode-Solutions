class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> a;
        a.push({s[0], 1});
        for(int i = 1; i < s.size(); i++){
            if(a.empty() == 0 && s[i] == (a.top()).first){
                if ((a.top()).second + 1 == k){
                    for(int j = 0; j < k-1; j++){
                        a.pop();
                    }
                } else {
                    a.push({s[i], (a.top()).second + 1});
                }
            } else {
               a.push({s[i], 1});
            }
        }
        string ans = "";
        while(!a.empty()){
            ans += (a.top()).first;
            a.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};