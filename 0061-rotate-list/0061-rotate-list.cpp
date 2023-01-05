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
int len(ListNode* head){
        int res=0;
        while(head){
                res++;
                head=head->next;
        }
        return res;
}
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
            if(head==NULL){
                    return head;
            }
        int n=len(head);
            k%=n;
            if(k==0){
                    return head;
            }
            ListNode* temp=head;
            ListNode* res;
            queue<int> s;
            k=n-k;
            while(k--){
                    s.push(temp->val);
                    temp=temp->next;
                    
            }
            res=temp;
            while(temp->next){
                    temp=temp->next;
            }
            while(s.size()){
                    temp->next=(new ListNode(s.front()));
                    s.pop();
                    temp=temp->next;
            }
            return res;
    }
        
};