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
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(INT_MAX);
            ListNode* start=dummy;
            stack<ListNode*> s,tmp;
            while(head){
                    while(s.size() && s.top()->val<head->val){
                            s.pop();
                    }
                    s.push(head);
                    head=head->next;
            }
            while(s.size()){
                    tmp.push(s.top());
                    s.pop();
            }
            while(tmp.size()){
                    dummy->next=tmp.top();
                    dummy=dummy->next;
                    tmp.pop();
            }
            return start->next;
            
    }
};