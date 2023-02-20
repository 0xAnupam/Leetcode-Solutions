struct Tries{
  int cnt=0;
  Tries* arr[26];      
};
int ans(string &s,Tries* root){
        int n=s.size();
        Tries* head=root;
        int i=0;
        while(i<n && head){
                if(head->arr[s[i]-'a']==NULL){
                        return 0;
                }
                head=head->arr[s[i++]-'a'];
        }
        return head ? head->cnt: 0;
}
int f(string &s,Tries* root){
        long long n=s.size(),res=0;
        for(int i=0;i<n;i++){
                for(char c='a';c<='z';c++){
                        if(s[i]!=c){
                                char t=s[i];
                                s[i]=c;
                                res+=ans(s,root);
                                s[i]=t;
                        }
                }
        }
        return res;
}
class Solution {
public:
    int countSubstrings(string s, string t) {
            Tries* root=new Tries();    
            int n=s.size(),m=t.size();
            for(int i=0;i<m;i++){
                    Tries* head=root;
                    for(int j=i;j<m;j++){
                            if(head->arr[t[j]-'a']==NULL){
                               head->arr[t[j]-'a']=new Tries();     
                            }
                            head=head->arr[t[j]-'a'];
                            head->cnt++;
                    }
                    
            }
            long long res=0;
            for(int i=0;i<n;i++){
                    string r="";
                    for(int j=i;j<n;j++){
                            r+=s[j];
                            res+=f(r,root);
                    }
            }
            return res;
    }
};