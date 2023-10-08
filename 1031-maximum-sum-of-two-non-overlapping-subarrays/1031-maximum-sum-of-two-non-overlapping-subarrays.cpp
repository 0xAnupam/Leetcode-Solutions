int f(vector<int>& nums,int a,int b){
        int n=nums.size();
        vector<int> dp(n+1,0);
        int maxi=0,sum=0,res=0;
        for(int i=0;i<a;i++){
                sum+=nums[i];
        }
        maxi=sum;
        for(int i=a;i<n;i++){
                dp[i]=maxi;
                sum-=nums[i-a];
                sum+=nums[i];
                maxi=max(maxi,sum);
        }
        sum=0;
        for(int i=0;i<b;i++){
                sum+=nums[i];
        }
        for(int i=b;i<n;i++){
                sum+=nums[i];
                sum-=nums[i-b];
                res=max(res,dp[i-b+1]+sum);
        }
        return res;
} 
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max( f(nums,firstLen,secondLen) , f(nums,secondLen,firstLen));
    }
};