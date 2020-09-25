# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        t = head
        l = head.next
        while t != None:
            if l == None:
                t.next = None
                break
            if t.val == l.val:
                l = l.next
            else:
                t.next = l
                t = t.next
        return head