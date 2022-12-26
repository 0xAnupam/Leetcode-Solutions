class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
            if(n%k){
                    return 0;
            }
            int K=n/k;
            map<int,int> mp;
            for(auto &i:nums){
                    mp[i]++;
            }
            while(K--){
                    auto p=(*mp.begin()).first;
                    for(int i=p;i<p+k;i++){
                            if(mp[i]==0){
                                    return 0;
                            }
                            if(mp[i]==1){
                                    mp.erase(i);
                            }
                            else{
                                    mp[i]--;
                            }
                    }
            }
            return 1;
    }
            
};