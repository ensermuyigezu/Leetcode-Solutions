class Solution:
    def firstUniqChar(self, s: str) -> int:
        d = {}
        for i in range(len(s)):
            if s[i] not in d:
                d[s[i]] = [True, i]
            else:
                d[s[i]][0] = False
        for i in d:
            if d[i][0] == True:
                return d[i][1]
        return -1