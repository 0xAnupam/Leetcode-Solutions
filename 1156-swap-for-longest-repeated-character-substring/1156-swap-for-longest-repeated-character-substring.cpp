class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> f(26,0);
            for(auto &i:text){
                    f[i-'a']++;
            }
            int i=0,n=text.size(),res=0;
            while(i<n){
                    char c=text[i];
                    int cnt=0;
                    while(i<n && text[i]==c){
                            i++;
                            cnt++;
                    }
                    int j=i;
                    i++;
                    res=max(res,cnt);
                    if(i<n && f[c-'a']>cnt){
                          while(i<n && text[i]==c){
                                  i++;
                                  cnt++;
                          }  
                            res=max(res,min(f[c-'a'],cnt+1));
                    }
                    i=j;
                    
            }
            reverse(text.begin(),text.end());
            i=0;
            while(i<n){
                    char c=text[i];
                    int cnt=0;
                    while(i<n && text[i]==c){
                            i++;
                            cnt++;
                    }
                    int j=i;
                    i++;
                    res=max(res,cnt);
                    if(i<n && f[c-'a']>cnt){
                          while(i<n && text[i]==c){
                                  i++;
                                  cnt++;
                          }  
                            res=max(res,min(f[c-'a'],cnt+1));
                    }
                    i=j;
                    
            }
            return res;
    }
};