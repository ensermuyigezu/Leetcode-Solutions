/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return l1;
        }
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode *c = new ListNode();
        if(l1->val < l2->val){
            c->val = l1->val;
            l1 = l1->next;
        } else {
            c->val = l2->val;
            l2 = l2->next;
        }
        auto i = l1;
        auto j = l2;
        auto k = c;
        while(i != NULL || j != NULL){
            if(i == NULL){
                k->next = j;
                break;
            } else if(j == NULL){
                k->next = i;
                break;
            }
            if(i->val <= j->val){
                k->next = i;
                i = i->next;
                k = k->next;
            } else {
                k->next = j;
                j = j->next;
                k = k->next;
            }
        }
        return c;
    }
};