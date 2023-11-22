void pre(int N,int* prime){
        for(int i=1;i<N;i++){
                if(i&1){
                        prime[i]=i;
                }
                else{
                        prime[i]=2;
                }
        }
        for(int i=3;i*i<N;i+=2){
                if(prime[i*i]==i*i){
                        for(int j=i*i;j<N;j+=i){
                                prime[j]=min(prime[j],i);
                        }
                }
        }
}
int sumOfFourDivisors(int n,int* prime){
        long long A=prime[n];
        if(n>1 && A*A*A==n){
                return A+A*A+n+1;
        }
        n/=A;
        if(n>1 && n==prime[n] && A!=n){
                return A+n+A*n+1;
        }
        return 0;
}
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        const int N=*max_element(nums.begin(),nums.end())+1;
            int prime[N];
            pre(N,prime);
            int res=0;
            for(auto &i:nums){

                    res+=sumOfFourDivisors(i,prime);
            }
            return res;
    }
};