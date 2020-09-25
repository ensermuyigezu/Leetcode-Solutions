class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        if N == 1: return 0
        current_length = 2**(N-1)
        if K > current_length // 2:
            return (self.kthGrammar(N-1, K - current_length/2) + 1) % 2
        else:
            return self.kthGrammar(N-1, K)