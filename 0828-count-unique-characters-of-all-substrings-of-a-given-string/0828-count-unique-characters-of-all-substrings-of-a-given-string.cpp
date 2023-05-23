class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.size();
        vector<int> f(26,n),F(26,n);
            long long res=0;
            for(int i=n-1;i>=0;i--){
                    F[s[i]-'A']=f[s[i]-'A'];
                    f[s[i]-'A']=i;
                    for(int j=0;j<26;j++){
                        res+=(F[j]-f[j]);
                    }
                    
            }
            return res;
    }
};