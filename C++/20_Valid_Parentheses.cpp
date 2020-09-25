class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0){
            return false;
        }
        if(s == "") return true;
        if(s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
        vector<char> l;
        for(char i : s){
            if(i == '(' || i == '[' || i == '{'){
                if(i == '('){
                    l.push_back(')');
                } else if(i == '['){
                    l.push_back(']');
                } else if(i == '{'){
                    l.push_back('}');
                }
            } else {
                char u = l.back();
                l.pop_back();
                if(i != u){
                    return false;
                }
            }
        }
        if(l.size() != 0){
            return false;
        }
        return true;
    }
};