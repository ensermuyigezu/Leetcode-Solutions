/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = new ListNode();
        ListNode *a = new ListNode();
        int carry = 0;
        auto f1 = l1;
        auto f2 = l2;
        if(l1->val + l2->val >= 10 && l1->next == NULL and l2->next == NULL){
            p->val = (f1->val + f2->val) % 10;
            ListNode *a = new ListNode(1);
            p->next = a;
            return p;
        }
        if(l1->val + l2->val >= 10){
            p->val = (f1->val + f2->val) % 10;
            carry = 1;
        } else {
            p->val = l1->val + l2->val;
        }
        auto f = p;
        f1 = l1->next;
        f2 = l2->next;
        while(f1 != NULL || f2 != NULL){
            ListNode *a = new ListNode();
            if(f1 == NULL){
                if(f2->val + carry >= 10){
                    a->val = (f2->val + carry) % 10;
                    carry = 1;
                } else {
                    a->val = f2->val + carry;
                    if(carry > 0){
                        carry = 0;
                    }
                }
                p->next = a;
                f2 = f2->next;
            } else if(f2 == NULL){
                if(f1->val + carry >= 10){
                    a->val = (f1->val + carry) % 10;
                    carry = 1;
                } else {
                    a->val = f1->val + carry;
                    if(carry > 0){
                        carry = 0;
                    }
                }
                p->next = a;
                f1 = f1->next;
            } else {
                if((f1->val + f2->val + carry) >= 10){
                    a->val = (f1->val + f2->val + carry) % 10;
                    p->next = a;
                    carry = 1;
                } else {
                    a->val = f1->val + f2->val + carry;
                    if(carry > 0){
                        carry = 0;
                    }
                    p->next = a;
                }
                f1 = f1->next;
                f2 = f2->next;
            }
            p = p->next;
        }
        if (carry != 0){
            a->val = carry;
            p->next = a;
        }
        return f;
    }
};