class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if matrix == []:
            return []
        return self.spiral_Order(matrix, len(matrix), len(matrix[0]), 0, 0, [])
        
    def spiral_Order(self, matrix, lr, lc, rs, cs, ll):
        if len(matrix) * len(matrix[0]) == len(ll):
            return
        self.printSpiral(matrix, rs, cs, lr, lc, ll)
        self.spiral_Order(matrix, lr - 2, lc - 2, rs + 1, cs + 1, ll)
        return ll

    def printSpiral(self, m, rs, cs, lr, lc, ll):
        l = []
        if lc == 1:
            for i in range(rs, rs+lr):
                l.append(m[i][cs])
            ll += l
            return ll
        l.append(m[rs][cs])
        for i in range(cs + 1, lc + cs):
            l.append(m[rs][i])
        for i in range(rs + 1, rs + lr):
            if cs + lc - 1 == cs:
                continue
            l.append(m[i][cs + lc - 1])
        a = []
        for i in range(rs+lc-2, rs, -1):
            if rs + lr -1 == rs:
                continue
            a.append(m[rs + lr - 1][i])
        l += a
        b = []
        for i in range(rs + lr-1, rs, -1):
            b.append(m[i][cs])
        if cs+lc-1 == 0:
            b.reverse()
        l += b
        ll += l
        return ll