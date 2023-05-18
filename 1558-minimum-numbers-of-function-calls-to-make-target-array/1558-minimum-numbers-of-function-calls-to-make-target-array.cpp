int bits(int n){
        int res=0;
        while(n){
                res++;
                n&=(n-1);
        }
        return res;
}
int f(int n){
        int res=0;
        for(int i=0;i<30;i++){
                if((1<<i)&n){
                        res=i;
                }
        }
        return res;
}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0,k=0;
            for(auto &i:nums){
                    res+=bits(i);
                    k=max(k,f(i));
            }
            return res+k;
    }
};