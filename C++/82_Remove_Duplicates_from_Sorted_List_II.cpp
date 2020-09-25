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
        return deleteDuplicates1(head);
    }
    ListNode* deleteDuplicates1(ListNode* head, ListNode* h = NULL){
        if(head->next == NULL){
            if(h == NULL || head->val != h->val){
                return head;
            }
            return NULL;
        }
        if(head->val != head->next->val && (h == NULL || head->val != h->val)){
            head->next = deleteDuplicates1(head->next);
            return head;
        } else {
            return deleteDuplicates1(head->next, head);
        }
        return NULL;
    }
};