# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        runner = current = head
        for i in range(n):
            if runner is None:
                return None
            runner = runner.next
        if runner == None:
            head = head.next
            return head
        while runner.next:
            current = current.next
            runner = runner.next
        current.next = current.next.next
        return head