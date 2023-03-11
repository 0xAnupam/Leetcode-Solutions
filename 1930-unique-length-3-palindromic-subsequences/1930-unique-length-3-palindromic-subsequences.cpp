class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
            vector<int> l(26,n),r(26,0);
            for(int i=0;i<n;i++){
                    if(l[s[i]-'a']==n){
                            l[s[i]-'a']=i;
                            
                    }
                    else{
                            r[s[i]-'a']=i;
                    }
            }
            int res=0;
            for(int i=0;i<26;i++){
                    int j=l[i]+1;int x=-1;
                    n=r[i];
                    while(j<n){
                            if((1<<(s[j]-'a'))&x){
                                    res++;
                                    x^=(1<<(s[j]-'a'));
                            }
                            
                            j++;
                    }
                    
            }
            return res;
    }
};