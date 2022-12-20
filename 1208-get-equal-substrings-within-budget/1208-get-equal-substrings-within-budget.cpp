class Solution {
public:
    int equalSubstring(string &s, string &t, int maxCost) {
            int n=s.size();
        vector<int> cost(n,0);
            for(int i=0;i<n;i++){
                    cost[i]=abs(s[i]-t[i]);
                    if(i){
                            cost[i]+=cost[i-1];
                    }
            }
            int res=0,sum=0;
            for(int i=0;i<n;i++){
                    auto p=upper_bound(cost.begin()+i,cost.end(),sum+maxCost)-cost.begin();
                    res=max(res,(int)p-i);
                    sum=cost[i];
            }
            return res;
            
            
    }
};