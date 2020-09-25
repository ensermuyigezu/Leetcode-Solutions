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
    stack<int> stack;
    vector<int> ans;
    vector<int> nextLargerNodes(ListNode* head) {
        if(head == NULL) return ans;
        nextLargerNodes1(head);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void nextLargerNodes1(ListNode* head) {
        if(head->next == NULL){
            ans.push_back(0);
            stack.push(head->val);
            return;
        }
        nextLargerNodes1(head->next);
        if(head->val < stack.top()){
            ans.push_back(stack.top());
            stack.push(head->val);
        } else if(head->val >= stack.top()){
            while(!stack.empty() && head->val >= stack.top()){
                stack.pop();
            }
            if(!stack.empty()){
                ans.push_back(stack.top());
            } else {
                ans.push_back(0);
            }
            stack.push(head->val);
        }
    }
};