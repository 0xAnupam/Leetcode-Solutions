int f(string &s,int n,int k,char c){
        int i=0,j=0,l=0,res=0;
        while(i<n){
                while(j<n && (l+(s[j]!=c)) <=k){
                        l+=(s[j]!=c);
                        j++;
                }
                res=max(j-i,res);
                l-=(s[i]!=c);
                i++;
        }
        return res;
}
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0,n=s.size();
            for(char c='A';c<='Z';c++){
                    res=max(res,f(s,n,k,c));
            }
            return res;
    }
};