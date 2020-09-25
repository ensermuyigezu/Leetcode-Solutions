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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        int s1 = findlength(l1);
        int s2 = findlength(l2);
        int diff = abs(s2-s1);

        if(s2 > s1) swap(l1, l2);
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        while(l1 && diff--){
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }

        while(l1){
            temp->next = new ListNode(l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        res = res->next;
        int carry = adjustList(res);

       if(carry){
            ListNode* fres = new ListNode(carry);
            fres->next = res;
            return fres;
        }
        return res;
    }
    int findlength(ListNode* head){
        int count = 0;
        while(head){
            head = head->next;
            count++;
        }
        return count;
    }
    int adjustList(ListNode* head){
        if(!head) return 0;
        int sum = adjustList(head->next) + head->val;
        head->val = sum % 10;
        return sum /10;
    }
};