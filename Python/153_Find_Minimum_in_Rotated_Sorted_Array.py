class Solution:
    def findMin(self, nums: List[int]) -> int:
        return self.find_Min(nums, 0, len(nums)-1)
    
    def find_Min(self, l, left, right):
        mid = (left + right) // 2
        if mid + 1 < len(l):
            if l[mid] < l[mid + 1] and l[mid] < l[mid - 1]:
                return l[mid]
        if right == left:
            return l[right]
        if l[left] < l[mid] and l[mid] > l[right]:
            return self.find_Min(l, mid + 1, right)
        elif l[mid] < l[left] or (l[left] < l[mid] and l[mid] < l[right]):
            return self.find_Min(l, left, mid - 1)
        elif left + 1 == right:
            return min(l[left], l[right])