int f[26];
class Solution {
public:
    bool makeEqual(vector<string>& words) {
            memset(f,0,sizeof(f));
            for(auto &s:words){
                    for(auto &c:s)f[c-'a']++;
            }
            int n=words.size();
            for(int i=0;i<26;i++){
                    if(f[i]%n)return 0;       
            }
            return 1;
    }
};