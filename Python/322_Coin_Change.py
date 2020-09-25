class Solution(object):
    def coinChange(self, coins, amount):
        b={}
        b[0]=0
        for i in range(1,amount+1):
            b[i]=float('inf')
        for i in range(1,amount+1):        
            for c in range(0,len(coins)):
                if i-coins[c]>=0:
            	    b[i]=min(b[i],b[i-coins[c]]+1)
        if b[amount]==float('inf'):
            return -1
        return b[amount]
        