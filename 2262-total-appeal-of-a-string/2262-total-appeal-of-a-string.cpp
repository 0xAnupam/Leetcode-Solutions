class Solution {
public:
    long long appealSum(string s) {
        int n=s.size();
            vector<int> f(26,n);
            long long res=0;
            for(int i=n-1;i>=0;i--){
                    f[s[i]-'a']=i;
                    for(int j=0;j<26;j++){
                        res+=(n-f[j]);
                    }
                    
            }
            return res;
    }
};