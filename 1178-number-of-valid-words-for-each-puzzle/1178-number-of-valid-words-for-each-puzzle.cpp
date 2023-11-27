struct tries{
  tries* next[2];
  int cnt=0;      
};
int mask(string &s){
        int res=0;
        for(auto &i:s){
                res|=(1<<(i-'a'));
        }
        return res;
}
void ins(tries* head,int n){
        
        for(int i=0;i<26;i++){
                bool f=(((1<<i)&n)>0);
                if(head->next[f]==nullptr)head->next[f]=new tries();
                head=head->next[f];
        }
        head->cnt++;
}
int MatchingAND(tries* head,int n,int i,int j){
        if(head==nullptr)return 0;
        if(i==26){
                return head->cnt;
        }
        if(i==j)return MatchingAND(head->next[1],n,i+1,j);
        if((1<<i)&n)return MatchingAND(head->next[0],n,i+1,j)+MatchingAND(head->next[1],n,i+1,j);
        return MatchingAND(head->next[0],n,i+1,j);
        
}
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        tries* head=new tries();
            for(auto &i:words){
                    ins(head,mask(i));
                    
            }
            int q=puzzles.size();
            vector<int> ans(q);
            for(int i=0;i<q;i++)ans[i]=MatchingAND(head,mask(puzzles[i]),0,puzzles[i][0]-'a');
            return ans;
    }
};