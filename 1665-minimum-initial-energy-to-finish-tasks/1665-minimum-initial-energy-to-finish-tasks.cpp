class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](const vector<int>&a,const vector<int>&b){
           if(b[1]-b[0]==a[1]-a[0]){
                   return a[1]<b[1];
           }
                return b[1]-b[0]<a[1]-a[0];
        });
            int extra=0,res=0;
            for(auto &i:tasks){
                   
                    if(extra>=i[1]){
                            extra-=(i[1]);
                            extra+=(i[1]-i[0]);
                    }else{
                    res+=i[1]-extra;
                    extra=i[1]-i[0];
                    }
            }
            return res;
    }
};