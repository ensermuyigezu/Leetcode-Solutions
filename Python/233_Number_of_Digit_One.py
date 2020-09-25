class Solution:
    def countDigitOne(self, n: int) -> int:
        if n < 0:
            return 0
        d = {0: [1, 1, 1, 1, 1, 1, 1, 1, 1]}
        self.init(n, d)
        return self.one(n, d)
    
    def one(self, n, d):
        a = str(n)
        s = 0
        k = 0
        for i in range(len(a)):
            if int(a[i]) == 0:
                continue
            if k != 0:
                s += k * (int(a[i]) * int("1" + (len(a) - i - 1) * "0"))
            if int(a[i]) == 1:
                k += 1
            s += d[(len(a) - i - 1)][int(a[i]) - 1]
        return s
    
    def init(self, n, d):
        a = str(n)
        for i in range(1, len(a) + 1):
            self.do(i, d)

    def do(self, n, d):
        d[n] = []
        a = self.one(int("1" + n * "0") - 1, d) + 1
        d[n].append(a)
        for i in range(1, 9):
            a = self.one(int("1" + n * "0") * (i + 1) - 1, d)
            d[n].append(a)