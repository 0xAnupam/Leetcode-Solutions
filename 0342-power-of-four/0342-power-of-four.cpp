class Solution {
public:
    bool isPowerOfFour(int n) {
            if(n==0){
                      return 0;
            }
            if(n==1){
                    return 1;
            }
            return (n%4)>0 ? 0 : isPowerOfFour(n/4);
    }
};