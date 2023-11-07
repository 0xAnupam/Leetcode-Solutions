class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
            int n=dist.size();
            for (int i=0;i<n;i++){
                    dist[i]=(dist[i]+speed[i]-1)/speed[i];
            }
            sort(dist.begin(),dist.end());
            int i=0;
            while(i<n && dist[i]>=i+1){
                    i++;
            }
            return i;
    }
};