int f(string &s,int idx,int n,long long cur,int k){
        if(idx==n){
                return 0;
        }

        cur<<=1;
        cur+=(s[idx]-'0');
        if(cur>k){
                return 0;
        }
        return 1+f(s,idx+1,n,cur,k);
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