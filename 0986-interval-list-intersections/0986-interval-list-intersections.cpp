class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
            map<int,vector<pair<int,int>>> mp;
            for(auto &i:firstList){
                    mp[i[0]].push_back({1,0});
                  //  mp[i[1]].push_back({-1,0});
            }
            for(auto &i:secondList){
                    mp[i[0]].push_back({1,1});
                   // mp[i[1]].push_back({-1,1});
                    
            }
             for(auto &i:firstList){
                    //mp[i[0]].push_back({1,0});
                    mp[i[1]].push_back({-1,0});
            }
            for(auto &i:secondList){
                    //mp[i[0]].push_back({1,1});
                   mp[i[1]].push_back({-1,1});
                    
            }
            int a=0,b=0,c=-1;
            vector<vector<int>> res;
            for(auto &i:mp){
                    for(auto &j:i.second){
                            if(j.second==0){
                                    a+=j.first;
                            }
                            else{
                                    b+=j.first;
                            }
                            if(a && b && c==-1){
                                  c=i.first;
                            }
                    }
                    
                    if(c!=-1 && (a==0 || b==0)){
                            res.push_back({c,i.first});
                            c=-1;
                    }
                    //cout<<i.first<<' '<<a<<' '<<b<<'\n';
            }
            return res;
        
    }
};