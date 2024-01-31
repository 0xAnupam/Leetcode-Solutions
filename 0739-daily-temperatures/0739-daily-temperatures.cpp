class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
            int n=temperatures.size();
            vector<int> res(n,0);
          
            for(int i=n-1;i>=0;i--){
                int q=1;
                    
                while(s.size()&& s.top().first<=temperatures[i]){
                      q+=s.top().second;
                      s.pop();
                   } 
            if(s.size()==0){
                    q=0;
            }        
            s.push({temperatures[i],q});
                    
            res[i]=s.top().second;
            }
            return res;
    }
};