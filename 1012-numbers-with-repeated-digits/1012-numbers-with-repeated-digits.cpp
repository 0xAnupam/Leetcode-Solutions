long long f(long long cur,long long k,long long n,long long avail){
        if(k==0){
                return cur<=n;
        }
        long long res=0;
        for(long long i=0;i<=9;i++){
                if(((1<<i)&avail)==0){
                        res+=f(10*cur+i,k-1,n,(avail|(1<<i)));
                }
        }
        return res;
}
long long digits(long long n){
        long long c=0;
        while(n){
                c++;
                n/=10;
        }
        return c;
}
long long F(long long n){
        if(n==0){
                return 0;
        }
        if(n==1){
                return 9;
        }
        long long res=9;
        long long cur =9;
        long long i=0;
        while(i<n-1){
                res*=cur;
                cur--;
                i++;
        }
        return res;
}
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        int k=digits(n);
            long long res=0;
            for(int i=1;i<=9;i++){
                    res+=f(i,k-1,n,(1<<i));
            }
            res=n-res;
            while(--k){
                    res-=F(k);
            }
            return res;
    }
};