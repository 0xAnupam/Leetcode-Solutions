class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int>> s;
            for(auto &i:points){
                    s.insert({i[0],i[1]});
            }
            int res=INT_MAX;
            int n=points.size();
            for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                            if(points[i][0]==points[j][0] || points[i][1]==points[j][1])continue;
                            if(s.find({points[i][0],points[j][1]})!=s.end() && s.find({points[j][0],points[i][1]})!=s.end()){
                                    
                                    res=min(res,abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]));
                            }
                            
                            
                    }
            }
            return res%INT_MAX;
    }
};