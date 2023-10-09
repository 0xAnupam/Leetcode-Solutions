struct tries{
  tries* arr[26];      
};
bool insert(tries* head,string &s,int i,int j){
        // cout<<i<<'\t'<<j<<'\n';
        bool res=0;
        for(int c=i;c<j;c++){
                if(head->arr[s[c]-'a']==nullptr){
                        res=1;
                        head->arr[s[c]-'a']=new tries();
                }
                head=head->arr[s[c]-'a'];
        }
        return res;
}
int f(string &s,tries* head,int n,int len){
        int res=0;
        for(int i=0;i<=n-len;i++){
                int j=i+len;
                int k=i;
                while(k<j && s[k]==s[k+len]){
                        
                        k++;
                }
           
                if(k==i+len){
                        
                  res+=insert(head,s,i,k);      
                }
                
        }
        return res;
}
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.size();
            int mid=1,res=0;
            tries* head=new tries();
            while(2*mid<=n){
                    res+=f(text,head,n,mid);
                    mid++;
            }
            return res;
    }
};