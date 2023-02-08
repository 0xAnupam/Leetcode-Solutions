class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
       map<int,vector<int> > m;
            int n=nums.size();
            for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                            m[nums[i]*nums[j]].push_back(i);
                    }
            }
            long long res=0;
            for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                           auto p=nums[i]*nums[j];
                            for(auto &k:m[p]){
                                    if(k!=i){
                                            res++;
                                    }
                            }
                    }
            }
            return 4*res;
            
    }
};