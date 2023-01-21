void f(int &ans,vector<int>& c,vector<int> &arr,int idx,int n,int k){
        if(idx==n){
                ans=min(ans,*(max_element(arr.begin(),arr.end())));
                return ;
        }
        for(int i=0;i<k;i++){
                arr[i]+=c[idx];
                f(ans,c,arr,idx+1,n,k);
                arr[i]-=c[idx];
        }
}
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> arr(k,0);
            int ans=1e6;
            f(ans,cookies,arr,0,cookies.size(),k);
            return ans;
    }
};