class Solution {
public:
        bool fun(vector<int> &l,vector<int> &h){
                for(int i=31;i>=0;i--){
                        if( h[i]-l[i]>1){return 0;}
                }
                return 1;
        }
    int longestNiceSubarray(vector<int>& nums) {
            int n=nums.size(),res=0;
            vector<vector<int>> adj(n+1);
            vector<int> f(32,0);
            adj[0]=f;
            for(int i=0;i<n;i++){
                    for(int j=0;j<32;j++){
                            if(nums[i]&(1<<j)){
                                    f[j]++;
                            }
                    }
                    adj[i+1]=f;
            }
            for(int i=0;i<n-res;i++){
                int l=i,h=min(i+31,n-1),m;
                    while(h-l>=0){
                            m=l+(h-l)/2;
                            if(fun(adj[i],adj[m+1])){
                                    res=max(res,m-i+1);
                                    l=m+1;
                            }
                            else{h=m-1;}
                    }
            }
            return res;
           
    }
};