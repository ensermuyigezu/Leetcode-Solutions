class Solution(object):
    def change(self, amount, coins):
        count = {}
        count[(0,0)] = 1
        count[(0, -1)] = 1
        count[(0, 1)] = 1
        for i in range(1, amount+1):
            count[(i, -1)] = 0
            count[(0, i)] = 1
        for k in range(len(coins)):
            for x in range(1, amount+1): 
                if x - coins[k] >= 0:
                    count[(x, k)] = count[(x-coins[k], k)] + count[(x, k-1)]
                else:   
                    count[(x, k)] = count[(x, k-1)]     
        return count[(amount, len(coins)-1)]
        