const int N=1e3+1;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int frequency[N];
        memset(frequency,0,sizeof(frequency));
        for(int &i:citations){
                frequency[i]++;
        }
        int cnt=0;
        for(int i=N-1;i>0;i--){
                cnt+=frequency[i];
                if(cnt>=i){
                        return i;
                }
        }    
            return 0;
    }
};