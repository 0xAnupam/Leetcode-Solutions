int f(string &s){
        vector<int> fre(26,0);
        for(auto &i:s){
                fre[i-'a']++;
        }
        for(auto &i:fre){
                if(i){
                        return i;
                }
        }
        return 0;
}
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fre,res;
            for(auto &i:words){
                    fre.push_back(f(i));
            }
            sort(fre.begin(),fre.end());
            int n=fre.size();
            for(auto &i:queries){
                    int p=f(i);
                   auto it=upper_bound(fre.begin(),fre.end(),p)-fre.begin();
                    res.push_back(n-it);
            }
            return res;
            
    }
};