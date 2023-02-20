class Solution {
public:
       
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
                return 1;
        }
        long long res=9,p=9;
            for(int i=1;i<n;i++){
                    res*=(p--);
            }
        return res+countNumbersWithUniqueDigits(n-1);
    }
};