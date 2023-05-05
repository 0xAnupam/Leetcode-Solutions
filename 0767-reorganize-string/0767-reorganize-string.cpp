class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        int f[26];
            
        memset(f,0,sizeof(f));
            for(auto &i:s){
                    f[i-'a']++;
            }
            for(int i=0;i<26;i++){
                    if(f[i]){
                            char c='a';c+=i;
                            pq.push({f[i],c});
                    }
            }
            int i=0,n=s.size();
            pair<int,int> P={0,'a'};
            while (pq.size()){
                   auto p=pq.top();
                    
                    pq.pop();
                    s[i]=p.second;
                    if(P.first){
                            pq.push(P);
                    }
                    //if(p.first){
                            P={p.first-1,p.second};
                    //}
                    i++;
                    
            }if(i<n){
                    return "";
            }
            for(int i=0;i<n-1;i++){
                    if(s[i]==s[i+1]){
                            return "";
                    }
            }
            return s;
    }
};