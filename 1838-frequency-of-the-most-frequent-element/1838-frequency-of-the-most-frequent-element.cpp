
long long Sum(vector<long long> &adj,int l,int r){
        
        return l ? adj[r]-adj[l-1]: adj[r];
}
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long sum=0,n=nums.size();
            vector<long long> adj;
            for(auto &i:nums){
                    sum+=i;
                    adj.push_back(sum);
            }
            long long res=1;
            for(long long i=0;i<n-res;i++){
                    long long l=i+1,h=n-1,m;
                    while(l<=h){
                            m=l+(h-l)/2;
                            if((nums[m]*(m-i+1))-Sum(adj,i,m)<=k){
                                    l=m+1;
                            }
                            else{
                                    h=m-1;
                            }
                    }
                    res=max(res,l-i);
            }
            return res;
            
    }
};