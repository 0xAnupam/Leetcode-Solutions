class Solution {
public:
    long long maximumSubsequenceCount(string s, string t) {
        long long res=0,i=0,n=s.size();
        long long a=0,b=0;
            while(i<n){
                    if(t[1]==s[i]){
                            a+=b;
                            res=max(res,a);
                            
                    }
                    if(t[0]==s[i]){
                            b++;
                    }
                    i++;
            }
            res=max(res,a+b);
            b=0;
            a=0;i--;
            while(i>=0){
                    if(t[0]==s[i]){
                            a+=b;
                            res=max(res,a);
                            
                    }
                    if(t[1]==s[i]){
                            b++;
                    }
                    i--;
            }
            res=max(res,a+b);
            return res;
            
            
    }
};