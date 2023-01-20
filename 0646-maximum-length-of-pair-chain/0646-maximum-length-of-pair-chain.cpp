class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int> &a,const vector<int>&b){
           if(a[1]==b[1]){
                   return a[0]<b[0];
           }
                return a[1]<b[1];
        });
            
            int res=0,pre=-1e4;
            for(auto &i:pairs){
                  
                    if(i[0]>pre){
                            res++;
                            pre=i[1];
                    }
            }
            return res;
    }
};