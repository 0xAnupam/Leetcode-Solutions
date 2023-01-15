struct trie{
int cnt=0;
trie* bit[2];
};
trie* root;
void insert(int x){
   trie* head=root;
   for(int i=30;i>=0;i--){
      if((1<<i)&x){
         if(head->bit[1]==NULL){
            head->bit[1]=new trie();
            
         }
         head=head->bit[1];
      }
      else{
         if(head->bit[0]==NULL){
            head->bit[0]=new trie();
         }
         head=head->bit[0];
      }
      head->cnt=head->cnt+1;
   }
}
int max_xor(int x){
   int res=0;
   trie* head=root;
   for(int i=30;i>=0;i--){
      if(head==NULL){
         return res;
      }
      if((1<<i)&x){
            if(head->bit[0] && head->bit[0]->cnt>0){
               res+=(1<<i);
               head=head->bit[0];
            }
            else if(head->bit[1] && head->bit[1]->cnt>0){
               head=head->bit[1];
            }
            else{
               return res;
            }
       }
       else{
         if(head->bit[1] && head->bit[1]->cnt>0){
            res+=(1<<i);
            head=head->bit[1];
         }
         else if(head->bit[0] && head->bit[0]->cnt>0){
            head=head->bit[0];
         }
         else{
            return res;
         }
       }
   }
   return res;
}
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        root=new trie();
            for(auto &i:nums){
                    insert(i);
            }
            int res=0;
            for(auto &i:nums){
                    res=max(res,max_xor(i));
            }
            return res;
    }
};