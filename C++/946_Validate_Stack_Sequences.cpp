class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        if(n == 0) return true;
        stack<int> stack;
        int i = 0; 
        int j = 0;
        stack.push(pushed[0]);
        i++;
        while(j < n){
            int pop = popped[j];
            if(stack.empty() || pop != stack.top()){
                while(true){
                    if(i >= n) return false;
                    if(pop == pushed[i]){
                        i++;
                        break;
                    }
                    stack.push(pushed[i]);
                    i++;
                }
            } else {
                stack.pop();
            }
            j++;
        }
        return true;
    }
};