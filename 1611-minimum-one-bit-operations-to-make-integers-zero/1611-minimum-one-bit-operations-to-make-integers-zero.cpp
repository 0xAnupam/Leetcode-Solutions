class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res=0;
        int t=1;
        for(int i=30;i>=0;i--){
                if((1<<i)&n){
                        res+=(t*((1<<(i+1))-1));
                        t*=-1;
                }        
        }
            return res;
    }
};