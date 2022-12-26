class Solution {
public: 
        int Time(string &s){
        int p=(s[0]-'0')*10+s[1]-'0';
        p*=60;
        p+=(s[3]-'0')*10+(s[4]-'0');
        return p;
}
        bool chor(vector<string> &time){
        map<int,int> f;
        for(auto &i:time){
                int p=Time(i);
              //  cout<<i<<' '<<p<<'\n';
                f[p]++;
                f[p+61]--;
                
        }
                int c=0;
                for(auto &i:f){
                        c+=i.second;
                        if(c>2){
                                return 1;
                        }
                }
                return 0;
}
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
            map<string,vector<string>> m;
            for(int i=0;i<keyName.size();i++){
                    m[keyName[i]].push_back(keyTime[i]);
            }
            vector<string> res;
            for(auto &i:m){
                    if(chor(i.second)){res.push_back(i.first);}
            }
            return res;
        
    }
};