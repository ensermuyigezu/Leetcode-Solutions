class Solution:
    def convert(self, s: str, numRows: int) -> str:
        ss = ""
        if numRows == 1:
            return s
        for i in range(numRows):
            k = i
            j = 0
            while k < len(s):
                ss += s[k]
                if i == 0:
                    k += 2 * (numRows - i - 1)
                elif i == numRows - 1:
                    k += 2 * i
                elif j % 2 == 0:
                    k += 2 * (numRows - i - 1)
                    j += 1
                else:
                    k += 2 * i
                    j += 1
        return ss
