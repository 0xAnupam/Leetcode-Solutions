bool pos(long long n,long long mid){
        long long q=mid*(mid+1);
        q/=2;
        if(q<n){
                return 0;
        }
        if((q-n)&1){
                return 0;
        }
        n=(q-n)/2;
        return n<=q;
}
class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
            long long t=target,q=sqrt(t);
            q=max(0LL,q);
            while(((q*q+q))<2*t){
                    q++;
            }
            while(pos(t,q)==0){
                    q++;
            }
            return q;
    }
};