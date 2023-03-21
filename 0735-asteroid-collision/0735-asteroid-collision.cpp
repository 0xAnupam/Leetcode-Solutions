class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
            for(auto &i:asteroids){
                    int cur=i;
                    while(s.size() && s.top()>0 && cur<0){
                            if(s.top()+cur==0){
                                    s.pop();
                                    cur=0;
                            }
                            else if(s.top()+cur>0){
                                    cur=0;
                            }
                            else{
                                    s.pop();
                            }
                            
                    }
                    if(cur){
                            s.push(cur);
                    }
            }
            vector<int> r;
            while(s.size()){
                    r.push_back(s.top());
                    s.pop();
            }
            reverse(r.begin(),r.end());
            return r;
    }
        
};