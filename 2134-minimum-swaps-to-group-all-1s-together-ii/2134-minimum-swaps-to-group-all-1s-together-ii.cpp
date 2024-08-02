class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for(int i=0;i<n;i++){
            nums.emplace_back(nums[i]);
            k+=nums[i];
        }
        if(k==0)return 0;
        int ans=n , sum=0;
        for(int i=0;i<k;i++)sum+=nums[i];
        ans=k-sum;
        for(int i=1;i<n;i++){
            sum-=nums[i-1];
            sum+=nums[i-1+k];
            ans=min(ans,k-sum);
        }
        return ans;
    }
};