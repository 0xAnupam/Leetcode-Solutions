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
    int numComponents(ListNode* head, vector<int>& nums) {
        int res=0,i=0,n=nums.size();
            set<int> s;
            for(auto &i:nums){
                    s.insert(i);
            }
            while(head ){
                   bool f=0;
                    while(head && s.find(head->val)!=s.end()){
                            s.erase(s.find(head->val));
                            head=head->next;
                            f=1;
                            
                    }
                    while(head && s.find(head->val)==s.end()){
                            head=head->next;
                    }
                    res+=f;
                  
                   
                    
            }
            return res;
    }
};