# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        f1 = l1
        f2 = l2
        if l1.val + l2.val>= 10 and l1.next == None and l2.next == None:
            p = ListNode((f1.val + f2.val)%10)
            a = ListNode(1)
            p.next = a
            return p
        if l1.val + l2.val>= 10:
            p = ListNode((f1.val + f2.val)%10)
            carry += 1
        else:
            p = ListNode(l1.val + l2.val)
        f = p
        f1 = l1.next
        f2 = l2.next
        while f1 != None or f2 != None:
            if f1 == None:
                if f2.val + carry >= 10:
                    a = ListNode((f2.val + carry)%10)
                    carry = 1
                else:
                    a = ListNode(f2.val + carry)
                    if carry > 0:
                        carry = 0
                p.next = a
                f2 = f2.next
            elif f2 == None:
                if f1.val + carry >= 10:
                    a = ListNode((f1.val + carry)%10)
                    carry = 1
                else:
                    a = ListNode(f1.val + carry)
                    if carry > 0:
                        carry = 0
                p.next = a
                f1 = f1.next
            else:
                if (f1.val + f2.val + carry) >= 10:
                    a = ListNode((f1.val + f2.val + carry)%10)
                    p.next = a
                    carry = 1
                else:
                    a = ListNode(f1.val + f2.val + carry)
                    if carry > 0:
                        carry = 0
                    p.next = a
                f1 = f1.next
                f2 = f2.next
            p = p.next
        if carry != 0:
            a = ListNode(carry)
            p.next = a
        return f
    