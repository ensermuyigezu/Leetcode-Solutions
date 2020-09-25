class Solution:
    def numDecodings(self, s: str) -> int:
        d = {}
        return self.num_Decodings(s, d)
    
    def num_Decodings(self, s, d):
        if s in d:
            return d[s]
        if len(s) < 1:
            return 1
        if len(s) == 1:
            if int(s[0]) >= 1:
                return 1
            else:
                return 0
        if int(s[0]) < 1:
            return 0
        a = self.num_Decodings(s[1:], d)
        if int(s[0] + s[1]) <= 26 and int(s[0] + s[1]) >= 1:
            a += self.num_Decodings(s[2:], d)
        d[s] = a
        return a