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
    ListNode* middleNode(ListNode* head) {
        if (head->next == NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast){
            if (fast->next == NULL) {
                return slow->next;
            }
            if (fast->next->next == NULL) {
                return slow->next;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return head;
    }
};