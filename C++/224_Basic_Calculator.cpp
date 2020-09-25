class Solution {
public:
    int calculate(string s) {
        stack<string> stack;
        int size = s.size();
        int operand = 0;
        int res = 0;
        int sign = 1;
        for(int i = 0; i < size; i++){
            string ch = getString(s[i]);
            if(isdigit(s[i])){
                operand = (operand * 10) + stoi(ch);
            } else if(s[i] == '+'){
                res += sign * operand;
                sign = 1;
                operand = 0;
            } else if(s[i] == '-'){
                res += sign * operand;
                sign = -1;
                operand = 0;
            } else if(s[i] == '('){
                stack.push(to_string(res));
                stack.push(to_string(sign));
                sign = 1;
                res = 0;
            } else if(s[i] == ')'){
                res += sign * operand;
                res *= stoi(stack.top());
                stack.pop();
                res += stoi(stack.top());
                stack.pop();
                operand = 0;
            }
            
        }
        return res + sign * operand;
    }
    string getString(char x) { 
        string s(1, x); 
        return s;    
    } 
};