long long f(long long n,vector<int> &mapping){
        if(n==0){
                return 0;
        }
        return mapping[n%10]+10*f(n/10,mapping);
}
class Solution {
public:
        
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<long long,int>> v;
           int n=nums.size();
            for(int i=0;i<n;i++){
                    if(nums[i]){
                    v.push_back({f(nums[i],mapping),i});}
                    else{
                            v.push_back({mapping[0],i});
                    }
            }
            sort(v.begin(),v.end());
            vector<int> res;
            for(auto &i:v){
                  res.push_back(nums[i.second]);
            }
            return res;
    }
};