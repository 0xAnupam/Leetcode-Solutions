vector<int> bits(int n){
        vector<int> res(32,0);
        for(int i=0;i<31;i++){
                if((1<<i)&n){
                        res[i]=1;
                }
        }
        return res;
}
bool ok(vector<int> &arr,int n)
{
        auto can_take=bits(n);
        for(int i=0;i<32;i++){
                if(can_take[i]+arr[i]>1){
                        return 0;
                }
        }
        for(int i=0;i<32;i++){
                arr[i]+=can_take[i];
        }
        return 1;
}
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(32,0);
            int i=0,j=0,res=0;
            while(i<n){
                    while(j<n && ok(arr,nums[j])){
                            j++;
                            res=max(res,j-i);
                    }

                    auto contri=bits(nums[i]);
                    for(int k=0;k<32;k++){
                            arr[k]-=contri[k];
                    }
                    i++;
            }
            return res;
    }
};