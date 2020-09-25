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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head->next == NULL || m == n) return head;
        vector<ListNode*> a;
        ListNode *dummy = new ListNode();
        a.push_back(dummy);
        while(head != NULL){
            a.push_back(head);
            head = head->next;
        }
        a.push_back(NULL);
        if(n - m == 1){
            a[m-1]->next = a[n];
            a[n-1]->next = a[m];
            a[m]->next = a[n]->next;
            a[n]->next = a[m];
            return m != 1 ? a[1] : a[n];
        }
        for(int i = n; i > m; i--){
            a[i]->next = a[i-1];
        }
        a[m]->next = a[n+1];
        a[m-1]->next = a[n];
        return m != 1 ? a[1] : a[n];
    }
};