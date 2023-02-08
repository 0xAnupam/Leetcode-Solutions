class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
            map<int,int> mp;
            for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                            
                            mp[nums[i]*nums[j]]++;
                            
                    }
            }
            int res=0;
            for(auto &i:mp){
                    res+=((i.second-1)*i.second);
            }
      
            return res*4LL;
    }
};