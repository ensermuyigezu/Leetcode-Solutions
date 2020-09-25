class Solution {
public:
    string countOfAtoms(string formula) {
        stack<pair<map<string, int>, int>> st;
        int idx = 0;
        map<string, int> vmap;
        int stack = 0;
        while (idx < formula.length()) {
            if (isalpha(formula[idx])) {
                int n = 0;
                map<string, int> mp;
                string s;
                while (idx < formula.length() && isalnum(formula[idx])) {
                    if (isalpha(formula[idx])) {
                        if (isupper(formula[idx])) {
                            if (n == 0) n = 1;
                            if (!s.empty())
                                mp[s] += n;
                            s.clear();
                            n = 0;
                        }
                        s.push_back(formula[idx]);
                    } else if (isdigit(formula[idx])) {
                        n = n * 10 + (formula[idx] - '0');
                    }
                    ++idx;
                }
                if (n == 0) n = 1;
                mp[s] += n;
                if (st.empty() || stack > st.top().second) {
                    st.push(make_pair(mp, stack));
                } else {
                    for (map<string, int> :: iterator it = mp.begin(); it != mp.end(); it++){
                        if (st.top().first.find(it->first) == st.top().first.end()) {
                            st.top().first.insert(make_pair(it->first, it->second));
                        } else {
                            st.top().first[it->first] += it->second;
                        }
                    }
                }
                if (formula[idx] == '(') {
                    ++idx;
                    stack++;
                }   
            } else if (formula[idx] == ')') {
                stack -= 1;
                map<string, int> mp = st.top().first;
                int num = st.top().second;
                st.pop();
                int count = 0;
                while (idx + 1 < formula.length() && isdigit(formula[idx + 1])) {
                    ++idx;
                    count = count * 10 + (formula[idx] - '0');
                }
                if (count == 0) {
                    count = 1;
                }
                for (map<string, int> :: iterator it = mp.begin(); it != mp.end(); it++) {
                    it->second *= count;
                }
                if (st.empty() || st.top().second != num - 1) {
                    st.push(make_pair(mp, num - 1));
                } else {
                        for (map<string, int> :: iterator it = mp.begin(); it != mp.end(); it++) {
                            if (st.top().first.find(it->first) == st.top().first.end()) {
                                st.top().first.insert(make_pair(it->first, it->second));
                            } else {
                                st.top().first[it->first] += it->second;
                            }
                        }
                }
                ++idx; 
            } else if (formula[idx] == '(') {
                idx++;
                stack++;
            }
        }
        
        string str;
        vmap = st.top().first;
        for (map<string, int> :: iterator it = vmap.begin(); it != vmap.end(); it++) {
            str.append(it->first);
            if (it->second > 1)
                str.append(to_string(it->second));
        }
        
        return str;
    }
};