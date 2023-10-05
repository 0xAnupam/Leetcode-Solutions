class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int p=1;
        int n=1;
        if(k==1){
                return 1;
        }
        while(n<=k){
                p*=10;
                p++;
                p%=k;
                n++;
                if(p==0){
                        return n;
                }
               
        }    
            return -1;
    }
};