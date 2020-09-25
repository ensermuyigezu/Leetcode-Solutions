class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        return self.word_Break(s, wordDict, 0, {})
    
    def word_Break(self, s, d, j, b):
        if s[j:] in b:
            return b[s[j:]]
        if j >= len(s):
            return True
        for i in range(len(d)):
            if s[j : j + len(d[i])] == d[i]:
                a = self.word_Break(s, d, j + len(d[i]), b)
                b[s[j + len(d[i]) :]] = a
                if a == True:
                    return True
        return False