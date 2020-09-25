class Solution:
    d = {}
    def generateParenthesis(self, n: int) -> List[str]:
        ll = []
        if n in self.d:
            return self.d[n]
        if n == 0:
            return ['']
        if n == 1:
            return ['()']
        else:
            for i in range(n):
                for j in self.generateParenthesis(i):
                    for k in self.generateParenthesis(n-i-1):
                        ll.append('(' + j + ')' + k)
            self.d[n] = ll
        return ll