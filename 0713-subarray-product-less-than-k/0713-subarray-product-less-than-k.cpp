class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       long long p=1,i=0,j=0,n=nums.size(),res=0,cnt=0;
            while(i<n){
                    p*=nums[i];
                    while(j<=i && p>=k){
                            p/=nums[j++];
                            
                    }
                    res+=(++i-j);
                  
            }
          
            return res;
    }
};