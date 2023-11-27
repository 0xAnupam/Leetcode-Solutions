char next(char c){
        return c=='z' ? 'a' : ++c;
}
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n=s.size();
            s+='#';
            int dp[n];
            for(int i=n-1;i>=0;i--){
                    if(next(s[i])==s[i+1]){
                            dp[i]=1+dp[i+1];
                    }
                    else{
                            dp[i]=1;
                    }
            }
            vector<int> res(26,0);
            for(int i=0;i<n;i++){
                    res[s[i]-'a']=max(dp[i],res[s[i]-'a']);
            }
            int ans=0;
            for(auto &i:res)ans+=i;
            return ans;
    }
};