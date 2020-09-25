class Solution:
    def search(self, nums: List[int], target: int) -> int:
        le = 0
        r = len(nums) - 1
        if nums == []:
            return -1
        return self.Search(nums, le, r, target)
    
    def Search(self, l, left, right, k):
        mid = (left+right)//2
        if k == l[mid]:
            return mid
        if right < left:
            return -1
        if l[left] < l[mid]:
            if k >= l[left] and k < l[mid]:
                return self.Search(l, left, mid - 1, k)
            else:
                return self.Search(l, mid+1, right, k)
        elif l[mid] < l[left]:
            if k > l[mid] and k <= l[right]:
                return self.Search(l, mid+1, right, k)
            else:
                return self.Search(l, left, mid-1, k)
        elif l[left] == l[mid]:
            if l[mid] != l[right]:
                return self.Search(l, mid+1, right, k)
            else:
                result = int(self.Search(l, left, mid-1, k))
                if result == -1:
                    return self.Search(l, mid+1, right, k)
                else:
                    return result
        return -1