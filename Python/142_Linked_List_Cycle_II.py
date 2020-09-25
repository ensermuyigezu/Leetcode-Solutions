# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return 
        slow = head.next
        fast = head.next.next
        while slow != fast:
            if fast == None or fast.next == None:
                return
            slow = slow.next
            fast = fast.next.next
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        return fast
