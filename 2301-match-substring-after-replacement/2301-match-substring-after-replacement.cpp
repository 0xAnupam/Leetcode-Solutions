class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        map<char,set<char>> mps;
        for(auto mping : mappings) 
            mps[mping[0]].insert(mping[1]);
        
        int n = s.size(),m = sub.size();
        
        for(int i=0;i<= n-m;i++){
            int k;
            for(k=0;k<m;k++){
                if(s[i+k] != sub[k] and mps[sub[k]].find(s[i+k]) == mps[sub[k]].end()) break;
            }
            
            if(k == m) return true;
        }
        
        return false;
    }
};