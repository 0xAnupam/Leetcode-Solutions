
class Solution {
public:
        int flag;
// vector<int> m[N];

vector<int> num;
vector<int> *m;
    int dfs(int u,int p,int &k){
        int sum=num[u];
        for(auto &x:m[u]){
               
            if(p!=x)
             sum+=dfs(x,u,k);
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
vector<pair<int,int>> ff(int n){
    vector<pair<int,int>> res;
        for(int i=2;i*i<=n;i+=2){
                if(n%i==0){
                        int cnt=0;
                        while(n>1 && n%i==0){
                                cnt++;
                                n/=i;
                        }
                        res.push_back({i,cnt});
                }
                if(i==2)i--;
        }
        if(n>1){
                res.push_back({n,1});
        }
    return res;
}
void factors(vector<pair<int,int>> &arr,int idx,int cur,vector<int> &ans){
    if(idx==arr.size()){
        ans.emplace_back(cur);
        return ;
    }
    factors(arr,idx+1,cur,ans);
    int mult=1;
    for(int j=1;j<=arr[idx].second;j++){
        mult*=arr[idx].first;
        factors(arr,idx+1,cur*mult,ans);
    }
}
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
            this->num=nums;
            vector<int> mm[n];
        for(auto &x:edges)
        {
            mm[x[0]].emplace_back(x[1]);
            mm[x[1]].emplace_back(x[0]);
        }
            this->m=mm;
        int sum=0;
        for(auto &x:nums) sum+=x;
        int ans=0;
        // for(int i=1;i<=sum;i++){
        //     if(sum%i==0){
        //         flag=1;
        //         dfs(0,-1,m,nums,sum/i);
        //         if(flag==1){
        //             ans=max(ans,i-1);
        //         }
        //     }
        // }
            auto p=ff(sum);
            vector<int> fact;
            factors(p,0,1,fact);
            sort(fact.rbegin(),fact.rend());
            for(auto &i:fact){
                    flag=1;
                    int k=sum/i;
                dfs(0,-1,k);
                if(flag==1){
                    return i-1;
                }
            }
        return ans;
    }
};