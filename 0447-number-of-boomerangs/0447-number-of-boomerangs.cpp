class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        long long res=0;
        int n=points.size();
        for(int i=0;i<n;i++){
                long long l=0;
                map<int,int> mp;
                for(int j=0;j<n;j++){
                        mp[pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2)]++;
                }
                mp[0]--;
                for(auto &j:mp){
                        res+=(j.second*(j.second-1));
                }
               
        }    
            return res;
    }
};