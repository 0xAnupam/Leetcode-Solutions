
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        long long sum=0,n=nums.size();
            int res=0,i=0,j=0;
            while(i<n){
                    while(j<n && (j-i+1)*1LL*nums[i]-sum-nums[j]<=k){
                            sum+=nums[j];
                            j++;
                            res=max(res,j-i);
                    }
                    sum-=nums[i];
                    i++;
            }
            
            return res;
            
    }
};