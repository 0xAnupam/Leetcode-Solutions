int bits(int n){
        int res=0;
        while(n){
                res++;
                n&=(n-1);
        }
        return res;
}
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i=0;i<=n;i++){
                res[i]=bits(i);
        }  
            return res;
    }
};