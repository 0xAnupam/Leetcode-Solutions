class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size() , i=0, grps[n] ,grpId=0;
        while(i<n){
            grps[i++]=grpId;
            while(i<n && (nums[i-1]&1)!=(nums[i]&1))grps[i++]=grpId;
            grpId++;
        }
        vector<bool> res;
        for(auto &i:queries)res.push_back(grps[i[0]]==grps[i[1]]);
        return res;
        
        
    }
};