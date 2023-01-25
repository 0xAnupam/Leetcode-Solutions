int f(vector<int> &arr,int idx,int n,int pre,int ele){
        if(idx==n){
                return ele%2==0;
        }
        if(ele%2==0 && arr[idx]==pre){
                return 1+f(arr,idx+1,n,pre,ele);
        }
        return f(arr,idx+1,n,arr[idx],ele+1);
        
}
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        return f(nums,0,nums.size(),-1,1);
    }
};