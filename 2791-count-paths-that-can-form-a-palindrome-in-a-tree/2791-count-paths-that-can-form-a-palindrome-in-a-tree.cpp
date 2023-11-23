class Solution {
public:
 long long f(int node,vector<int>*adj,unordered_map<int,long long>&mp,int mask,string &s){
       long long res=mp[mask]++;
         for(int i=0;i<26;i++){
                 int newMask=(1<<i)^mask;
                 res+=mp[newMask];
         }
         for(auto &i:adj[node]){
                 int newMask=mask^(1<<(s[i]-'a'));
                 res+=f(i,adj,mp,newMask,s);
         }
         return res;
   }    
    long long countPalindromePaths(vector<int>& parent, string s) {
        unordered_map<int,long long> mp;
            int mask=0;
            int n=s.size();
            vector<int> adj[n];
            for(int i=1;i<n;i++){
                    adj[parent[i]].emplace_back(i);
            }
            return f(0,adj,mp,0,s);
            
    }
};