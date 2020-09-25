# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head == None:
            return False
        l = []
        current = head
        while current:
            l.append(current)
            current = current.next
        for i in range((len(l)//2)+1):
            if i == len(l)//2:
                l[i].next = None
            else:
                l[i].next = l[len(l)-1-i]
                l[len(l)-1-i].next = l[i+1]
        return l[0]
        
        