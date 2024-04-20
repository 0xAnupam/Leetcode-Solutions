bool prime(int n){
        if(n==1)return 0;
        if(n<4)return 1;
        if(!(n&1))return 0;
        for(int i=3;i*i<=n;i+=2)if(n%i==0)return 0;
        
        return 1;
}
class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int x=-1,y,n=nums.size();
            for(int i=0;i<n;i++){
                    if(prime(nums[i])){
                            if(x==-1)x=i;
                            y=i;
                    }
            }
            return y-x;
    }
};