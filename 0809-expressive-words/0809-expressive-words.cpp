vector<pair<char,int>>  formatter(string &s){
  
        int i=0,n=s.size();
        vector<pair<char,int>> res;
        while(i<n){
                char c=s[i];
                int cnt=0;
                while(i<n && c==s[i]){
                        i++;
                        cnt++;
                }
                res.push_back({c,cnt});
        }
        return res;
}
bool match(vector<pair<char,int>> &arr,string &s){
        auto p=formatter(s);
        if(arr.size()!=p.size()){
                return 0;
        }
        int n=arr.size();
        for(int i=0;i<n;i++){
                if(arr[i].first!=p[i].first){
                        return 0;
                }
                if(arr[i].second<p[i].second){
                        return 0;
                }
                if(arr[i].second!=p[i].second && arr[i].second<3){
                        return 0;
                }
        }
        return 1;
}
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        auto p=formatter(s);
            int res=0;
            for(auto &i:words){
                    res+=match(p,i);
            }
            return res;
    }
};