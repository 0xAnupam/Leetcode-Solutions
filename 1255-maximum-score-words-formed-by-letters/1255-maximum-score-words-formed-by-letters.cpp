const int N=(1<<15);
int dp[15][N];
bool can(vector<int> f,string s){
        for(auto &i:s){
                f[i-'a']--;
                if(f[i-'a']<0){
                        return 0;
                }
        }
        return 1;
}
vector<int> new_fre(vector<int> f,string s){
        for(auto &i:s){
                f[i-'a']--;
                
        }
        return f;
}
int F(vector<int> &f,vector<int>&score,vector<string>& words,int idx,int n,int cur){
        if(idx==n){
                return 0;
        }
        if(dp[idx][cur]!=-1){
                return dp[idx][cur];
        }
        if(can(f,words[idx])){
                auto p=new_fre(f,words[idx]);
                int res=0;
                for(auto &i:words[idx]){
                        res+=score[i-'a'];
                }
                return dp[idx][cur]=max(res+F(p,score,words,idx+1,n,cur+(1<<idx)),F(f,score,words,idx+1,n,cur));
        }
        return dp[idx][cur]=F(f,score,words,idx+1,n,cur);
        
}
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        memset(dp,-1,sizeof(dp));
            vector<int> f(26,0);
            for(auto &i:letters){
                    f[i-'a']++;
            }
            
            return F(f,score,words,0,words.size(),0);
    }
};