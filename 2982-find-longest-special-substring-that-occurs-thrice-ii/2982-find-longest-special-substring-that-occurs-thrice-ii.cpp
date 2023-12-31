class Solution {
public:
    int maximumLength(string s) {
            
            int n=s.size(),i=0;
            int mp[26][n+1];
            memset(mp,0,sizeof(mp));
            int res=0;
            while(i<n){
                    int cnt=0;
                    char c=s[i];
                    while(i<n && s[i]==c){
                            cnt++;
                            i++;
                            mp[c-'a'][cnt]++;
                            if(mp[c-'a'][cnt]>2)res=max(res,cnt);
                            if(cnt>1)mp[c-'a'][cnt-1]++;
                    }
                    res=max(res,cnt-2);
            }
            return res==0 ? -1: res;
    }
};