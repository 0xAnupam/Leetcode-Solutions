bool isSubSequence(string &a,string &b){
        if(b.size()>a.size()){
                return 0;
        }
        int j=0;
        for(auto &i:a){
                if(i==b[j]){
                        j++;
                        if(j==b.size()){
                                return 1;
                        }
                }
        }
        return 0;
}
int dp[11][(1<<10)+1];
int f(string &s,vector<string>& strs,int idx,int n,string &tmp,int x){
        int cnt=0;
        if(idx==n){
                for(auto &i:strs){
                        cnt+=isSubSequence(i,tmp);
                }
                if(cnt>1){
                        return -100;
                }
                return 0;
        }
        if(dp[idx][x]!=-1){
                return dp[idx][x];
        }
        int res=f(s,strs,idx+1,n,tmp,x);
        string t=tmp;
        t+=s[idx];
        res=max(res,1+f(s,strs,idx+1,n,t,(x|(1<<idx))));
        return  dp[idx][x]=res;
}
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
     int res=-1;
            for(auto &i:strs){
                    string tmp="";
                    memset(dp,-1,sizeof(dp));
                    res=max(res,f(i,strs,0,i.size(),tmp,0));
            }
            return res==0 ? -1 : res;
    }
};