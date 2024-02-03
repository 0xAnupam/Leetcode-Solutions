class Solution {
public:
    int flag;
    int dfs(int u,int p,vector<vector<int>> &m,vector<int> &nums,int k){
        int sum=nums[u];
        for(int i=0;i<m[u].size();i++){
                int x=m[u][i];
            if(p!=x)
             sum+=dfs(x,u,m,nums,k);
        }
        if(sum>k)
        {
            flag=0;
            return 0;
        }
        else if(sum==k)
         return 0;
        return sum;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector <vector<int>> m(n);
        for(auto &x:edges)
        {
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        int sum=0;
        for(auto &x:nums) sum+=x;
        int ans=0;
        for(int i=1;i<=sum;i++){
            if(sum%i==0){
                flag=1;
                dfs(0,-1,m,nums,sum/i);
                if(flag==1){
                    ans=max(ans,i-1);
                }
            }
        }
        return ans;
    }
};