# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        return self.deleteDuplicates1(head)
    
    def deleteDuplicates1(self, head, h=None):
        if head.next == None:
            if h == None or head.val != h.val:
                return head
            return None
        if head.val != head.next.val and (h == None or head.val != h.val):
            head.next = self.deleteDuplicates1(head.next)
            return head
        else:
            return self.deleteDuplicates1(head.next, head)
