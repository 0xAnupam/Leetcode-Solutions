class Solution {
public:
    int maxScore(string &s) {
            int n=s.size(),res=0;
            int a=0,b=0;
            for(auto &i:s)b+=(i-'0');
            for(int i=0;i<n-1;i++){
                    a+=(s[i]=='0');
                    b-=(s[i]-'0');
                    res=max(res,a+b);
            }
            return res;
    }
};