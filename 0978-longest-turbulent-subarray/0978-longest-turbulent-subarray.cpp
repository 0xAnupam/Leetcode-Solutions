int dp[40002][2];
        int max_len(vector<int>& arr,int i,int f){
                if(i>=arr.size()){
                        return 0;
                }
                if(dp[i][f]!=-1){
                       return dp[i][f];
                }
                
                if(f==0){
                        if(i+1<arr.size() && arr[i+1]>arr[i]){
                                return dp[i][f]=1+max_len(arr,i+1,1);
                        }
                        return 0;
                }
                else{
                        if(i+1<arr.size() && arr[i+1]<arr[i]){
                                return dp[i][f]=1+max_len(arr,i+1,0);
                        }
                        return 0;
                }
                return dp[i][f]=1;
        }
class Solution {
public:
        
    int maxTurbulenceSize(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
            int res=0;
            for(int i=0;i<arr.size();i++){
                    res=max(res,1+max_len(arr,i,1));
                    res=max(res,1+max_len(arr,i,0));
            }
            
         return res;
    }
};