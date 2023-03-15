class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
     map<string ,long long > mp;
            for(auto &s:cpdomains){
                    int rep=0;
                    int i=0,n=s.size();
                    while(i<n && s[i]!=' '){
                            rep*=10;
                            rep+=(s[i]-'0');
                            i++;
                    }
                    int j=i;
                    i=n-1;
                     string t="";
                    while(i>j){
                            while(i>j && s[i]!='.'){
                                    t+=s[i--];
                            }
                            string s=t;
                            t+='.';
                            mp[s]+=rep;
                            i--;
                    }
                    
            }
            vector<string> res;
            for(auto &i:mp){
                    
                    string s=i.first;
                    reverse(s.begin(),s.end());
                    s=to_string(i.second)+' '+s;
                    res.push_back(s);
            }
            return res;
    }
};