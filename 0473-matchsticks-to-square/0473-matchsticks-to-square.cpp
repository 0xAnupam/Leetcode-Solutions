bool f(vector<int> &nums,int idx,int n,int a,int b,int c,int d,int sum){
        if(idx==n){
                return (a==b && b==c && c==d );
        }
        if(a>sum || b>sum || c> sum || d>sum){
                return 0;
        }
        
        return (f(nums,idx+1,n,a+nums[idx],b,c,d,sum)||f(nums,idx+1,n,a,b+nums[idx],c,d,sum)|| f(nums,idx+1,n,a,b,c+nums[idx],d,sum)|| f(nums,idx+1,n,a,b,c,d+nums[idx],sum));
}
class Solution {
public:
    bool makesquare(vector<int>& nums) {
          long long sum=0;
            for(auto &i:nums){
                    sum+=i;
            }
                if(sum%4){
                        return 0;
                }
            sort(nums.rbegin(),nums.rend());
            return f(nums,0,nums.size(),0,0,0,0,sum/4);
    }
};