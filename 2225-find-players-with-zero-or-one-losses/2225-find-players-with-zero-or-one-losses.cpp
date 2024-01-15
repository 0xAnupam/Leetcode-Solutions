class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
            vector<int> loss(100001,0),play=loss;
            
            for(auto &i:matches){
                    loss[i[1]-1]++;
                    play[i[1]-1]++;
                    play[i[0]-1]++;
            }
            vector<vector<int>> answer(2,vector<int>());
            for(int i=0;i<1e5+1;i++){
                    if(loss[i]<2 &&(play[i])){
                            answer[loss[i]].emplace_back(i+1);
                    }
                    
            }
            return answer;
    }
};