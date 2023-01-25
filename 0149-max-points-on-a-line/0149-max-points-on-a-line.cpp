class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(); 
            int res=0;
            
           for(int i=0;i<n;i++){map<pair<int,int>,int> mp;
                    for(int j=i+1;j<n;j++){
        int x=points[j][0]-points[i][0],y=points[j][1]-points[i][1],p=__gcd(y,x);
                           if(p){ 
                                  x/=p;
                                  y/=p;
                           }
                            mp[{x,y}]++;
                    }
                    for(auto &i:mp){
                    res=max(res,i.second);
            }
         }
           
            return 1+res;
    }
        
};