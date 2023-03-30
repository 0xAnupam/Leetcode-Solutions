class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& r, int veganFriendly, int maxPrice, int maxDistance) {
        int n=r.size();
            for(int i=0;i<n;i++){
                    swap(r[i][0],r[i][1]);
            }
            sort(r.rbegin(),r.rend());
            vector<int> res;
            if(veganFriendly==0){
            for(auto &i:r){
                    if(i[3]<=maxPrice && i[4]<=maxDistance){
                    res.emplace_back(i[1]);}
            }
          }
            else{
                   for(auto &i:r){
                        if(i[2] && i[3]<=maxPrice && i[4]<=maxDistance){
                                  res.emplace_back(i[1]);
                        }
               } 
            }
            return res;
    }
};