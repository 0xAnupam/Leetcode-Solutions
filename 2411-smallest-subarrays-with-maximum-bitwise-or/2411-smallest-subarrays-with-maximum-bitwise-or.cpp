int idx(vector<vector<int>> &f,int i){
        int res=i;
        for(int j=0;j<30;j++){
                auto p=lower_bound(f[j].begin(),f[j].end(),i);
                if(p!=f[j].end()){
                        res=max(res,*p);
                }
        }
        return res;
}
int k(int n){
        int res=0;
        while(n){
                res++;
                n>>=1;
        }
        return res;
}
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<vector<int>> f(30,vector<int>());
            int j=0;
            for(auto &n:nums){
                    int q=k(n);
                    for(int i=0;i<=q;i++){
                            if((1<<i)&n){
                                    f[i].push_back(j);
                            }
                            
                    }
                    j++;
            }
            int n=nums.size();
            vector<int> res(n);
            for(int i=0;i<n;i++){
                    res[i]=1-i+idx(f,i);
            }
            
        return res;
        
    }
};