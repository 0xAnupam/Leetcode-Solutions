class Solution {
public:
    int minimumBuckets(string s) {
        int i=0,n=s.size(),res=0;
        while(i<n){
                if(s[i]=='H'){
                        if(i && s[i-1]=='X'){
                                ;
                        }
                        else if(i<n-1 && s[i+1]=='.'){
                                res++;
                                s[i+1]='X';
                        }
                        
                        else if(i && s[i-1]=='.'){
                                res++;
                        }
                        
                        else{
                                return -1;
                        }
                }
                i++;
        }
           
            return res;
    }
};