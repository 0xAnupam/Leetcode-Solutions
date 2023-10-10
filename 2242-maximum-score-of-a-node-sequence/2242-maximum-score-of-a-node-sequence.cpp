int f(vector<pair<int,int>>* arr,int node,int a,int b){
        for(auto &i:arr[node]){
                if(i.second!=node && i.second!=a && i.second!=b){
                        return i.first;
                }
        }
        return -1;
}
class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n=scores.size();
        vector<pair<int,int>> arr[n];
            for(auto &i:edges){
                    arr[i[0]].push_back({scores[i[1]],i[1]});
                    arr[i[1]].push_back({scores[i[0]],i[0]});
            }
            for(int i=0;i<n;i++){
                    sort(arr[i].rbegin(),arr[i].rend());
            }
            long long res=-1;
            for(int i=0;i<n;i++){
                    for(auto &j:arr[i]){
                            if(j.second>i){
                                    for(auto &k:arr[j.second]){
                                            if(k.second!=i && k.second!=j.second){
                                                    int scr=f(arr,i,j.second,k.second);
                                                    if(scr!=-1){
                                                            res=max(res,0LL+scores[i]+j.first+k.first+scr);
                                                            // break;
                                                            
                                                    }
                                            }
                                    }
                            }
                    }
            }
            return res;
    }
};