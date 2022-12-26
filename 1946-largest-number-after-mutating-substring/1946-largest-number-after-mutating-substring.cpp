class Solution {
public:
    string maximumNumber(string &s, vector<int>& change) {
        int i=0,n=s.size();
            while(i<n && change[s[i]-'0']<=s[i]-'0'){
                    i++;
            }
            while(i<n && change[s[i]-'0']>=s[i]-'0'){
                    s[i]=change[s[i]-'0']+'0';
                    i++;
            }
            return s;
    }
};