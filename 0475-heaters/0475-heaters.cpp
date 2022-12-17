class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
          
        sort(heaters.begin(),heaters.end());
            long long res=0,n=heaters.size(),r;
            for(auto &i:houses){
                    auto p=lower_bound(heaters.begin(),heaters.end(),i)-heaters.begin();
                        r=1e18;
                        if(p<n){
                                
                                r=abs(heaters[p]-i);
                        }
                        p--;
            if(p>=0){
                    r=min(r,(long long)abs(heaters[p]-i));
            }
                    
            res=max(res,r);
                    
                                
            }
        return res;
    }
};