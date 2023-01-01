class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        map<int,vector<int>> mp;
            int n=nums.size();
            for(int i=0;i<n;i++){
                    mp[nums[i]].push_back(i);
            }
            int res=0,b=0,a=n+1;
            for(auto &i:mp){
                    for(auto &j:i.second){
                            
                            a=min(a,j);
                            res=max(res,j-a);
                           
                    }
                   
            }
            return res;
            
    }
};