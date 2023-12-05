class Solution {
public:
    int numberOfMatches(int n) {
        int res=0;
            while(n){
                    res+=n/2;
                    if(n==1)return res;                       
                    n=(n+1)/2;
            }
            return res;
    }
};