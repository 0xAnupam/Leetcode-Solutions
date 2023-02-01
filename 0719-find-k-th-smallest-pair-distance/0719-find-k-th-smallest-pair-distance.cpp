long long helper(vector<int>& nums,long long mid) {
        long long c=0;
        for(long long i=0;i<nums.size();i++)
        {
            long long p=upper_bound(nums.begin()+i,nums.end(),nums[i]+mid)-nums.begin();
            long long cnt=p-i-1;
            c+=cnt;
        }
        return c;
    }
class Solution {
public:
    
    int smallestDistancePair(vector<int>& nums, int k) {
        long long n=nums.size();
        sort(nums.begin(),nums.end());
        long long ei=nums[n-1]-nums[0];
        long long si=nums[1]-nums[0];
        for(long long i=0;i<n-1;i++)
         si=min(si,1LL*nums[i+1]-nums[i]);
        while(si<=ei)
        {
            long long mid=si+(ei-si)/2;
            if(helper(nums,mid)>=k){
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
        }
        return si;
    }
};