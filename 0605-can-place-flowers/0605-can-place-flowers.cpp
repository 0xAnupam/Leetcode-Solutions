class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int N) {
        int n=flowerbed.size();
            int i=0;
            
            while(i<n){
                    int cnt=0;
                    while(i<n && flowerbed[i]){
                            i++;
                            cnt++;
                    }
                    if(cnt){
                            cnt=-1;
                    }
                    
                    while(i<n && flowerbed[i]==0){
                            i++;
                            cnt++;
                    }
                    if(i==n){
                            cnt++;
                    }
                    
                    N-=(cnt)/2;
                    if(N<=0){
                            return 1;
                    }
                    
            }
            return 0;
    }
};