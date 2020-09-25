# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None and l2 == None:
            return l1
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        if l1.val < l2.val:
            c = ListNode(l1.val)
            l1 = l1.next
        else:
            c = ListNode(l2.val)
            l2 = l2.next
        i = l1
        j = l2
        k = c
        while i != None or j != None:
            if i == None:
                k.next = j
                break
            elif j == None:
                k.next = i
                break
            if i.val <= j.val:
                k.next = i
                i = i.next
                k = k.next
            else:
                k.next = j
                j = j.next
                k = k.next
        return c
