bool omk(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2,long long mid){
        long long lcm=divisor1*1LL*divisor2/__gcd(divisor1,divisor2);
        long long a=mid-(mid/divisor1);
        long long b=mid-(mid/divisor2);
        long long c=mid-(mid/divisor1)-(mid/divisor2)+(mid/lcm);
        
        return a+b-c>=uniqueCnt2+uniqueCnt1 && a>=uniqueCnt1 && b>=uniqueCnt2;
}
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int l=1,h=INT_MAX,m;
            while(l<=h){
                    m=l+(h-l)/2;
                    if(omk(divisor1,divisor2,uniqueCnt1,uniqueCnt2,m)){
                            h=m-1;
                    }
                    else{
                            l=m+1;
                    }
            }
            return l;
            
    }
};