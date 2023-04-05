class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long i=1;
            while((i*(i+1)*(i+2))<2LL*neededApples){
                    i++;
            }
            return 4LL*(i+i%2);
    }
};