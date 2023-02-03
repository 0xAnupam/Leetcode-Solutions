
int n;class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
            int n=items.size();
            
            vector<int> res,l;
            int maxi=0;
            for(auto &i:items){
                    maxi=max(maxi,i[1]);
                    l.emplace_back(maxi);
            }
            for(auto &i:queries){
                   vector<int> temp;temp.push_back(i+1);
                    auto p=lower_bound(items.begin(),items.end(),temp)-items.begin();
                   if(p!=0){
                           p--;
                           res.emplace_back(l[p]);
                   }
                    else{
                            res.push_back(0);
                    }
                    
            }
            return res;
    }
};