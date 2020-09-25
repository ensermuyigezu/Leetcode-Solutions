class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = {};
        int m_cnt = 0;
        for (int begin = 0, end = 0; end < s.size(); end++) {
            m_cnt = max(m_cnt, ++cnt[s[end] - 'A']);
            if (end - begin - m_cnt >= k)
                --cnt[s[begin++] - 'A'];
        }
        return min((int)s.size(), m_cnt + k);
    }
};