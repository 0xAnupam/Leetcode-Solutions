class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int,char>> pq;
        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});
        
        string s="";
        while(pq.size()){
                auto p=pq.top();
                pq.pop();
                if(p.first<1){
                        return s;
                }
                if(s.size()>1 && s[s.size()-2]==s[s.size()-1] && s[s.size()-1]==p.second){
                        auto P=pq.top();
                        pq.pop();
                        if(P.first<1){
                                return s;
                        }
                        s+=P.second;
                        P.first--;
                        pq.push(P);
                        pq.push(p);
                        
                }
                else{
                        s+=p.second;
                        p.first--;
                        pq.push(p);
                }
        }
            return s;
    }
};