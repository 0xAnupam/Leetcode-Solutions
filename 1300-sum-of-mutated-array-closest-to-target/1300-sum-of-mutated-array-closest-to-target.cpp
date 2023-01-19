int f(vector<int> &arr,vector<int>&nums,int i,int n){
         auto p=upper_bound(arr.begin(),arr.end(),i)-arr.begin();
                   
                    int k=nums[p];
                    if(p<n){
                            k-=arr[p];
                    }
                    k+=(n-p)*i;
        return k;
}
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
            int n=arr.size();
        vector<int> nums(n);
            int sum=0;
            int diff=1e9+1,res=diff;
            for(int i=0;i<n;i++){
                    sum+=arr[i];
                    nums[i]=sum;
            }
            nums.push_back(sum);
            int l=0,h=arr[n-1],m;
            while(l<=h){
                    m=l+(h-l)/2;
                    int k=f(arr,nums,m,n);
                    if(k==target){
                            return m;
                    }
                    if(k<target){
                            l=m+1;
                    }
                    else{
                            h=m-1;
                    }
                    if(abs(target-k)<diff){
                            diff=abs(target-k);
                            res=m;
                    }
                    if(abs(target-k)==diff){
                            
                            res=min(res,m);
                    }
                    
                    
            }
            return res;
    }
};