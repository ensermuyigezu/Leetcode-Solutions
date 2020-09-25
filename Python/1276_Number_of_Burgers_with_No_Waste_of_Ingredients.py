class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        if tomatoSlices == 0 and cheeseSlices == 0:
            return [0, 0]
        a = (tomatoSlices - (2 * cheeseSlices))/2
        b = cheeseSlices - a 
        if a >= 0 and b >= 0 and (a*10)%10 == 0 and (b*10)%10 == 0:
            return [int(a), int(b)]
        else:
            return []