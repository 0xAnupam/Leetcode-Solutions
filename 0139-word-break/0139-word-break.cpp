class Solution {
public:
    void KMP(string& s,string& t,vector<vector<int>>& v) {
        int n = s.length(), m = t.length();
        int lps[n+1]; lps[0] = 0; int j = 0;
        for(int i=1;i<n;i++) {
            while(j!=0 and s[j]!=s[i]) j = lps[j-1];
            lps[i] = j+=(s[j]==s[i]);
        }
        j = 0;  
        for(int i=0;i<m;i++) {
            while(j!=0 and s[j]!=t[i]) j = lps[j-1];
            j+=(s[j]==t[i]);
			//push all starting indices of match
            if(j==n)   { v[i].push_back(i-j+1); j = lps[j-1]; }
        }
    }

    bool wordBreak(string s, vector<string>& arr) {
        int n = s.length();
        vector<vector<int>> v(n);    
		 //precompute matches
        for(string x : arr) KMP(x,s,v);
        vector<bool> dp(n+1,0); dp[0] = 1;
        for(int i=0;i<n;i++) {
            for(int j : v[i]) {
                if(dp[j]) { 
                    dp[i+1] =1; break;
                }
            }
        }
        return dp[n];
    }
};