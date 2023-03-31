class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<pair<int,int>> v;
            int n=word.size();
            int i=0;
            while(i<n){
                    char c=word[i];
                    int cnt=0;
                    while(i<n && c==word[i]){
                            i++;
                            cnt++;
                    }
                    v.push_back({c,cnt});
            }
            n=v.size()-4;
            int res=0;
            i=0;
            while(i<n){
                    if(v[i].first=='a' && v[i+1].first=='e' && v[i+2].first=='i' &&v[i+3].first=='o' &&v[i+4].first=='u'){
                            res=max(res,v[i].second+v[i+1].second+v[i+2].second+v[i+3].second+v[i+4].second);
                    }
                    char c=v[i].first;
                    while(i<n && c==v[i].first ){
                            i++;
                    }
            }
            return res;
    }
};