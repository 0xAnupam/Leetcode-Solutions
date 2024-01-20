class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<pair<long long,long long>> s,t;
        long long res=0,m=1e9+7; 
            vector<long long > l(n,0),r=l;
            for(int i=0;i<n;i++){
                    long long q=1;
                while(s.size() && s.top().first>=arr[i]){
                       q+=s.top().second;
                        s.pop();
                }
               if(s.size()){
                       auto p=s.top();
                       s.push({arr[i],q});
               }
                else{
                        s.push({arr[i],q});
                }
                    l[i]=s.top().second;
        }
            for(int i=n-1;i>=0;i--){
                    long long q=1;
                while(t.size() && t.top().first>arr[i]){
                       q+=t.top().second;
                        t.pop();
                }
               if(t.size()){
                       auto p=t.top();
                       t.push({arr[i],q});
               }
                else{
                        t.push({arr[i],q});
                }
                   r[i]=t.top().second;
        }
            for(int i=0;i<n;i++){
                   
                    res+=(l[i]*r[i]*arr[i])%m;
                    res%=m;
            }
      
        
            
            return res;
    }
};