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
const int N=1e4+1;
int arr[N];
int n;
class Solution {
public:
    Solution(ListNode* head) {
        n=0;
        while(head){
                arr[n++]=head->val;
                head=head->next;
        }    
    }
    
    int getRandom() {
        int x=rand();
            x%=n;
            return arr[x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */