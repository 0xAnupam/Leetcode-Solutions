class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0){
                return 0;
                
        }
            if(k==0){
                    if(num%10==0){
                            return 1;
                    }
                    return -1;
            }
            for(int i=1;i*k<=num;i++)
            {
                    int l=num-i*k;
                    l%=10;
                    if(l==0){
                            return i;
                    }
            }
            return -1;
    }
};