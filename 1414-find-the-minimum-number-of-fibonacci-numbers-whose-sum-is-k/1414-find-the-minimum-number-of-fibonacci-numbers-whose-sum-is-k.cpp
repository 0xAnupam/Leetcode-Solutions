class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        long long v[48];
            v[0]=v[1]=1;
            for(long long i=2;i<48;i++){
                    v[i]=v[i-1]+v[i-2];
            }
            int l=47;
            int res=0;
            while(k){
                    res++;
                    while(v[l]>k){
                            l--;
                    }
                    k-=v[l];
            }
            return res;
    }
};