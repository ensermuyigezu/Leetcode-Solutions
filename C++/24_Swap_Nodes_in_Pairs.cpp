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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        auto f = head;
        auto s = head->next;
        auto p = head->next->next;
        head = s;
        while(true){
            s->next = f;
            if(p == NULL){
                f->next = NULL;
                break;
            } else if (p->next == NULL){
                f->next = p;
                break;
            } else {
                f->next = p->next;   
            }
            f = p;
            s = p->next;
            p = p->next->next;
        }
        return head;
    }
};