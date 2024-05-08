bool omk(vector<int> &a,vector<int> &b){
        int x=-1;
        for(int i=0;i<26;i++){
                if(b[i]==0)continue ;
                if(a[i]==0 || b[i]%a[i])return 0;
                if(x==-1){
                        x=(b[i]/a[i]);
                }
                else if(x!=(b[i]/a[i]))return 0;
        }
        return 1;
}
int omk2(vector<int> &x,int n, int k){
        int req=x[k-1];
        for(int i=2*k-1;i<n;i+=k){
                if((x[i]^x[i-k])!=req)return 0;
        }
                   return 1;
}
class Solution {
public:
    int minAnagramLength(string s) {
        vector<int> a(26,0),b(26,0);
            
            for(auto &i:s)b[i-'a']++;
            int n=s.size();         
            vector<int> x(n);
            int y=0;
            for(int i=0;i<n;i++){
                     y^=(1<<(s[i]-'a'));
                     x[i]=y;
            }
            for(int i=0;i<n;i++){
                    a[s[i]-'a']++;
                    if(omk(a,b) && omk2(x,n,i+1))return i+1;
            }
            return n;
    }
};