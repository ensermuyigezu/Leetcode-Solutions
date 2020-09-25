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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        auto t = head;
        auto l = head->next;
        while(t != NULL){
            if(l == NULL){
                t->next = NULL;
                break;
            }
            if(t->val == l->val){
                l = l->next;
            } else {
                t->next = l;
                t = t->next;
            }
        }
        return head;
    }
};