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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> nodes;
        ListNode *head = new ListNode(0);
        auto point = head;
        for(auto x : lists){
            while(x != NULL){
                nodes.insert(x->val);
                x = x->next;
            }
        }
        while(!nodes.empty()){
            int x = *nodes.begin();
            nodes.erase(nodes.begin());
            ListNode *y = new ListNode(x);
            point->next = y;
            point = point->next;
        }
        return head->next;
    }
};