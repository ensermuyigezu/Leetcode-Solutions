class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0
        j = len(height)-1
        m = 0
        while i < j:
            if height[i] >= height[j]:
                if (min(height[i], height[j]) * (j-i)) > m:
                    m = min(height[i], height[j]) * (j-i)
                j -= 1
            else:
                if (min(height[i], height[j]) * (j-i)) > m:
                    m = min(height[i], height[j]) * (j-i)
                i += 1
        return m