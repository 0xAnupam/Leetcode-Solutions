class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=0,n=0;
            set<pair<long long,int>> s;
            for(auto &i:nums){
                    sum+=i;
                    s.insert({sum,n++});
             }
          if(sum==x){
                  return n;
                  
          }
            if(sum<x){
                    return -1;
            }
            long long res=n;
            sum=0;
           
            for(int i=n-1;i>=0 && sum<=x;i--){
                    sum+=nums[i];
                    auto p=s.lower_bound({x-sum,-1});
                    if(p!=s.end() && (*p).first+sum==x){
                            res=min(res,1+n-i+(*p).second);
                    }
                    if(sum==x){
                            res=min(res,n-i);
                    }
                    
            }
            auto p=s.lower_bound({x,0});
            if(p!=s.end() && (*p).first==x){
                    res=min((*p).second+1LL,res);
            }
            return res==n ? -1:res;

    }
};