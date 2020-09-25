class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> a;
        string ans = "";
        for(char x : S){
            if (a.empty()) a.push(x);
            else if (x == a.top()) a.pop();
            else a.push(x);
        }
        while(!a.empty()){
            ans += a.top();
            a.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};