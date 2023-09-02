int dp[100];
struct tries{
  int f=0;
  tries* arr[26];      
};
void ins(string &s,tries* head){
        for(auto &i:s){
                if(head->arr[i-'a']==nullptr){
                        head->arr[i-'a']=new tries();
                }
                head=head->arr[i-'a'];
        }
        head->f=1;
}

int f(string &s,int idx,int n,tries* head){
        if(idx==n){
                return 0;
        }
        if(dp[idx]!=-1){
                return dp[idx];
        }
        int res=1+f(s,idx+1,n,head);
        tries* temp=head;
        int i=idx;
        while(i<n && temp->arr[s[i]-'a']){
                res=min(res,i-idx+1+f(s,i+1,n,head));
                
                temp=temp->arr[s[i]-'a'];
                if(temp->f){
                        res=min(res,f(s,i+1,n,head));
                }
                i++;
        }
        while(i<n){
                res=min(res,i-idx+1+f(s,i+1,n,head));
                i++;
        }
        return dp[idx]=res;
}
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
            memset(dp,-1,sizeof(dp));
            tries* head=new tries();
            for(auto &i:dictionary){
                    ins(i,head);
            }
            return f(s,0,s.size(),head);
            
    }
};