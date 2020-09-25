# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        a = self.reverse_List(head, None)
        head.next = None
        return a[1]
    
    def reverse_List(self, head, x):
        if head.next == None:
            x = head
            return True, x
        a = self.reverse_List(head.next, x)
        if a[0]:
            head.next.next = head
        return a