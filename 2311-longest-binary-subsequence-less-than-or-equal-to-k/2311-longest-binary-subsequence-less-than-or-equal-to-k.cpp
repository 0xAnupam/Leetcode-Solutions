int f(string &s,int idx,int n,long long cur,int k){
        if(idx==n){
                return 0;
        }
        int res=1;
        if(s[idx]=='1' && cur){
                int i=idx+1;
                while(i<n && s[i]=='1'){
                        i++;
                }
        //        res=f(s,i,n,cur,k);
        }
        cur*=2;
        cur+=(s[idx]-'0');
        if(cur>k){
                return 0;
        }
        return max(res,1+f(s,idx+1,n,cur,k));
}
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res=0,cnt=0,i=0,n=s.size();
            while(i<n){
                    if(s[i]=='0'){
                            cnt++;
                    }
                    else{
                            res=max(res,cnt+f(s,i,n,0,k));
                    }
                    i++;
            }
            return max(res,cnt);
    }
};