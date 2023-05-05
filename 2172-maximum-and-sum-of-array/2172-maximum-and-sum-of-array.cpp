int dp[10][524290];
int f(vector<int>&nums,int slot,int cur,int n){
        if(slot==0){
                return 0;
        }
        if(dp[slot][cur]!=-1){
                return dp[slot][cur];
        }
         int vis[16];
        memset(vis,0,sizeof(vis));
        int res=f(nums,slot-1,cur,n);
        for(int i=0;i<n;i++){
                if(((1<<i)&cur)==0 && (nums[i]&slot) && vis[nums[i]]==0){
                        
                        vis[nums[i]]=1;
                        res=max(res,(nums[i]&slot)+f(nums,slot-1,cur+(1<<i),n));
                        int new_cur=cur+(1<<i);
                        int j=i+1;
                        int V[16];
                        memset(V,0,sizeof(V));
                        while(j<n){
                                 if(((1<<j)&new_cur)==0 && (nums[j]&slot) && V[nums[j]]==0){
                                         V[nums[j]]=1;
                                      res=max(res,(nums[i]&slot)+(nums[j]&slot)+f(nums,slot-1,new_cur+(1<<j),n));   
                                 }
                                j++;
                        }
                        
                }
        }
        return dp[slot][cur]=res;
}
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
            memset(dp,-1,sizeof(dp));
        return f(nums,numSlots,0,nums.size());
    }
};