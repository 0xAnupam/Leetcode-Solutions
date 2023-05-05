class Solution {
public:
    int maxVowels(string s, int k) {
        int f[26];
        memset(f,0,sizeof(f));
        f[0]++;
        f[4]++;
        f[8]++; 
        f[14]++;
        f[20]++;
        int sum=0,n=s.size();
        for(int i=0;i<k;i++){
                sum+=f[s[i]-'a'];
        }
        int res=sum;
        for(int i=k;i<n;i++){
                sum-=f[s[i-k]-'a'];
                sum+=f[s[i]-'a'];
                res=max(res,sum);
        }    
            return res;
    }
};