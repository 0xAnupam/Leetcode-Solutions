class Solution {
public:
    int buyChoco(vector<int>& prizes, int money) {
        int res=money+1;
            int n=prizes.size();
            for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                            if(prizes[i]+prizes[j]<=money){
                                    res=min(res,prizes[i]+prizes[j]);
                            }
                    }
            }
            if(res>money){
                    return money;
            }
            
            return money-res;
            
    }
};