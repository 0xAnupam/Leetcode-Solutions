class Solution {
public:
    long long minimumMoney(vector<vector<int>>& tr) {
        sort(tr.begin(),tr.end(),[](const vector<int>&a,const vector<int>&b){
           if(a[1]==b[1]){
                   return a[0]>b[0];
           }   
                return a[1]<b[1];
        });
            long long res=0,s=0;
            for(auto &i:tr){
                    res=max(res,i[0]+s);
                    s+=max(0,i[0]-i[1]);
            }
            
            return res;
    }
        
};