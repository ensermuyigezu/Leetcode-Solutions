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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        auto current = head->next;
        auto next = current->next;
        head->next = NULL;
        while(true){
            auto temp = head;
            if(current->val <= head->val){
                current->next = head;
                head = current;
            } else {
                while(true){
                    if(current->val >= temp->val && (temp->next == NULL || current->val <= temp->next->val)){
                        current->next = temp->next;
                        temp->next = current;
                        break;
                    } else {
                        temp = temp->next;
                    }
                }
            }   
            current = next;
            if(current == NULL) break;
            next = current->next;
        }
        return head;
    }
};