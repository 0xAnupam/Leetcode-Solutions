class Solution {
public:
    int twoEggDrop(int n) {
       long long l=1,h=n,m;
            while(l<=h){
                    m=l+(h-l)/2;
                    if(m*(m+1)<2*n){
                            l=m+1;
                    }
                    else{
                            h=m-1;
                    }
            }
            return l;
    }
};