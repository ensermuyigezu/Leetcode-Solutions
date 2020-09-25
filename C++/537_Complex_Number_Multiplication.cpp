class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int x0, y0, x1, y1;
        vector<int> first = extract(a);
        vector<int> second = extract(b);
        x0 = first[0];
        y0 = first[1];
        x1 = second[0];
        y1 = second[1];
        return to_string(x0*x1 - y0*y1) + "+" + to_string(y0*x1 + x0*y1) + "i";
    }
    vector<int> extract(string s){
        vector<int> ans(2);
        string a;
        string b;
        int i = 0;
        while(s[i] != '+' && i < s.size()){
            a += s[i];
            i++;
        }
        if(a == "") ans[0] = 0;
        else ans[0] = stoi(a);
        i++;
        while(s[i] != 'i' && i < s.size()){
            b += s[i];
            i++;
        }
        if(b == "") ans[1] = 0;
        ans[1] = stoi(b);
        return ans;
    }
};