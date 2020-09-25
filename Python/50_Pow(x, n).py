class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            return 1/self.poww(x, abs(n))
        else:
            return self.poww(x, n)
        
    def poww(self, x, n):
        k = n//2
        if n == 0:
            return 1
        i = self.poww(x, abs(k))
        if n%2 == 0:
            if n < 0:
                return 1/(i*i)
            else:
                return  i * i
        else:
            if n < 0:
                return 1/(i*i*x)
            else:
                return  i * i * x