class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        memo = {}
        for i in range(0, len(s)):
            memo[i] = 1
        d = {}
        d[i] = [s[len(s)-1]]
        for i in range(len(s)-2, -1, -1):
            d[i] = [s[i]]
            if s[i] not in d[i+1]:
                new = 1 + memo[i+1]
                if new > memo[i]:
                    memo[i] = new
                    d[i] = [s[i]]
                    d[i] += d[i+1]
            elif s[i] != s[i+1]:
                memo[i] += 1
                d[i] += s[i+1]
                j = i+2
                while s[i] != s[j]:
                    memo[i] += 1
                    d[i].append(s[j])
                    j += 1
        return max(memo.values())
        