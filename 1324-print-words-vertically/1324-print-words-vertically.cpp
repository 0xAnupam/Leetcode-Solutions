class Solution {
public:
    vector<string> printVertically(string s) {
        int n=s.size();
            int maxi=0,cnt=0;
            int p=0;
            vector<vector<char>> dp(200,vector<char>(200,' '));
            for(auto &i:s){
                    if(i==' '){
                            cnt++;
                            p=0;
                    }
                    else{
                            dp[cnt][p]=i;
                            p++;
                    }
                    maxi=max(maxi,p);
            }
            
            vector<string> res(maxi,"");
            for(int i=0;i<maxi;i++){
                    int p=0;
                    for(int j=0;j<=cnt;j++){
                           
                            res[i]+=dp[j][i];
                            if(dp[j][i]!=' '){
                                    p=j;
                            }
                    }
                    
                    res[i].erase(remove_if(res[i].begin()+p, res[i].end(), ::isspace), res[i].end());
            }
            return res;
    }
};