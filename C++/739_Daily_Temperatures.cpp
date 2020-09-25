class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size(), 0);
        stack<int> stack;
        for(int i = T.size() - 1; i >= 0; --i){
            while(!stack.empty() && T[i] >= T[stack.top()]){
                stack.pop();
            }
            ans[i] = stack.empty() ? 0 : stack.top() - i;
            stack.push(i);
        }
        return ans;
    }
};