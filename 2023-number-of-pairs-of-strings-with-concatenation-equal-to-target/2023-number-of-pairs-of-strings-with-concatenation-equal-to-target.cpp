class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        map<string,int> mp;
            for(auto &i:nums){
                    mp[i]++;
            }
            int res=0;
            int n=target.size()-1;
            int i=0;
            string a="";
            while(i<n){
                    a+=target[i++];
                    int j=i;
                    string b="";
                    while(j<=n){
                            b+=target[j++];
                    }
                    if(mp.find(a)!=mp.end() && mp.find(b)!=mp.end()){
                        if(a.size()==b.size() && a==b){
                            res+=(mp[a]*(mp[a]-1));
                        }
                        else{
                                res+=mp[a]*mp[b];
                        }
                    }
                   
            }
            return res;
            
    }
};