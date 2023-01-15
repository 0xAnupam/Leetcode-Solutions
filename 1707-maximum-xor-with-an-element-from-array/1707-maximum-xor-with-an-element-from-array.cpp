struct trie{
int cnt=INT_MAX;
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
      head->cnt=min(head->cnt,x);
   }
}
int max_xor(int x,int m){
   int res=0;
   trie* head=root;
   for(int i=30;i>=0;i--){
      if(head==NULL){
         return res;
      }
      if((1<<i)&x){
            if(head->bit[0] && head->bit[0]->cnt<=m){
               res+=(1<<i);
               head=head->bit[0];
            }
            else if(head->bit[1] && head->bit[1]->cnt<=m){
               head=head->bit[1];
            }
            else{
               return -1;
            }
       }
       else{
         if(head->bit[1] && head->bit[1]->cnt<=m){
            res+=(1<<i);
            head=head->bit[1];
         }
         else if(head->bit[0] && head->bit[0]->cnt<=m){
            head=head->bit[0];
         }
         else{
            return -1;
         }
       }
   }
   return res;
}
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        root=new trie();
            for(auto &i:nums){
                    insert(i);
            }
            
            vector<int> res;
            for(auto &i:queries){
                    res.push_back(max_xor(i[0],i[1]));
            }
            return res;
    }
};