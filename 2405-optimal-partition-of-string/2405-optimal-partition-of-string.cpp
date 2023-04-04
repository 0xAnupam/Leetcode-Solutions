class Solution {
public:
    int partitionString(string &s) {
        int st[26];
        memset(st,0,sizeof(st));
        int res=1;
        for(auto &i:s){
                if(st[i-'a']){
                        res++;
                        memset(st,0,sizeof(st));
                }
                st[i-'a']++;
           
        }
            return res;
    }
};