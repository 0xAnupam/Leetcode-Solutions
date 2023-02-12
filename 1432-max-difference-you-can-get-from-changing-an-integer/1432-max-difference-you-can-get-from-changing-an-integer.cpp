
class Solution {
public:
    int maxDiff(int num) {
       string s=to_string(num);
        int i=0,p=0,q=0,n=s.size();
            char c=s[0];
            while(i<n && s[i]<='1'){
                    i++;
            }
            if(i<n){
                    int inc=1;
                    if(s[i]!=s[0]){
                            inc--;
                    }
                    for(auto &j:s){
                            p*=10;
                            if(j!=s[i]){
                                    p+=(j-'0');
                            }
                            else{
                                    p+=inc;
                            }
                    }
            }
            else{
                    p=pow(10,n)-1;
                    p/=9;
                    p=min(p,num);
            }
            i=0;
            while(i<n && s[i]=='9'){
                    i++;
            }
            if(i<n){
                    for(auto &j:s){
                            q*=10;
                            if(j==s[i]){
                                    q+=9;
                            }
                            else{
                                    q+=(j-'0');
                            }
                    }
            }
            else{
                    q=num;
            }
           
          
            return q-p;
            
        
    }
        
};