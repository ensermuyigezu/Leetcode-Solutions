class Solution:
    def hammingWeight(self, n: int) -> int:
        x = 0
        for i in str(bin(n)):
            if i == '1':
                x += 1
        return x