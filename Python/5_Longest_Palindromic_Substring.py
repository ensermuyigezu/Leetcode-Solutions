class Solution:
    def longestPalindrome(self, s: str) -> str:
        if s == '':
            return ''
        best_len = 0
        for parity in [0, 1]:
            low = 1
            high = len(s)
            if low % 2 != parity:
                low += 1
            if high % 2 != parity:
                high -= 1
            while low <= high:
                mid = (low + high) // 2
                if mid % 2 != parity:
                    mid += 1
                if mid > high:
                    break
                tmp = self.good(mid, s)
                if tmp != -1:
                    if mid > best_len:
                        best_len = mid
                        best_s = s[tmp : tmp + mid]
                    low = mid + 2
                else:
                    high = mid - 2
        return best_s
    
    def is_palindrome(self, s):
        rev = list(s)
        rev.reverse()
        rev = "".join(rev)
        return s == rev

    def good(self, x, s):
        for L in range(len(s) - x + 1):
            if self.is_palindrome(s[L : L + x]):
                return L
        return -1