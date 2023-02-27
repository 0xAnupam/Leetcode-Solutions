class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
            int n=nums.size();
        vector<long long> psum;
            long long sum=0;
            for(auto &i:nums){
                    sum+=i;
                    psum.emplace_back(sum);
            }
            long long res=0;
            for(int i=0;i<n;i++){
                    long long l=i,h=n-1,m;
                    while(l<=h){
                            m=l+(h-l)/2;
                            long long tsum=psum[m]-psum[i]+nums[i]*1LL;
                            tsum*=(m-i+1);
                            if(tsum<k){
                                    l=m+1;
                            }
                            else{
                                    h=m-1;
                            }
                            
                            
                    }
                    res+=(l-i);
            }
        return res;
    }
};