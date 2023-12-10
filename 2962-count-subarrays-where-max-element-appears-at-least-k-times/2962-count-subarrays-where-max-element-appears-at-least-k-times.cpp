class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        int cnt=0;
        long long res=0,n=nums.size(),i=0,j=0;
        while(i<n){
            while(j<n && ((maxi==nums[j])+cnt<k)){
                cnt+=(maxi==nums[j]);
                
                j++;
            }
            res+=(j-i);
            cnt-=(nums[i]==maxi);
            i++;
        }
        res=(n*(n+1))/2-res;
        return res;
    }
};