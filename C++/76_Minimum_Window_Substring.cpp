
class Solution {
public:    
    string minWindow(string s, string t) {
        unordered_map<char, int> table;
        for(char c : t){
            table[c]++;
        }
        int begin = 0, end = 0;
        int counter = table.size();
        int len = INT_MAX;
        string ans = "";
        while(end < s.length()){
            char endchar = s[end];
            if(table.find(endchar) != table.end()){
                table[endchar]--;
                if(table[endchar] == 0) counter--;
            }
            end++;
            while(counter == 0){
                if(end-begin < len){
                    len = end - begin;
                    ans = s.substr(begin, end - begin); 
                }
                int startchar = s[begin];
                if(table.count(startchar) == 1){
                   table[startchar]++;
                   if(table[startchar] > 0) counter++; 
                }
                begin++;
            }
        }
        return ans;
    }
};

