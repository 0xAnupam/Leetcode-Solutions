long long TrailingZeroes(long long n){
        long long res=0;
        for (long long i = 5; n >= i; i *= 5){
                res+=(n/i);
        }
        
        return res;
}
class Solution {
public:
    int preimageSizeFZF(int k) {
        long long l=k,h=10LL*k,m;
            while(l<=h){
                    m=(l+h)/2;
                    if(TrailingZeroes(m)<k){
                         l=m+1;   
                    }
                    else{
                         h=m-1;
                    }
            }
           
            int res=0;
            while(TrailingZeroes(l)==k){
                    res++;
                    l++;
            }
            return res;
    }
};