class Solution:
    def countSubstrings(self, s: str) -> int:
        k = 0
        for mid in range(len(s)):
            x = 0
            while mid - x >= 0 and mid + x < len(s):
                if s[mid - x] != s[mid + x]:
                    break
                k += 1
                x += 1
        for mid in range(len(s) - 1):
            x = 1
            while mid - x + 1 >= 0 and mid + x < len(s):
                if s[mid - x + 1] != s[mid + x]:
                    break
                k += 1
                x += 1
        return k