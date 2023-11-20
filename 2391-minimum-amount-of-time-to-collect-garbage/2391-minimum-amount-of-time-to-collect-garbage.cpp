class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g=0,p=0,m=0,n=travel.size();
            long long res=0;
            for(int i=1;i<n;i++)
            {  
               travel[i]+=travel[i-1];     
            }
            for(int i=0;i<garbage.size();i++){
                    res+=garbage[i].size();
                    for(auto &j:garbage[i]){
                            if(j=='G'){
                                    g=i;
                            }
                            else if(j=='M'){
                                    m=i;
                            }
                            else{
                                    p=i;
                            }
                    }
                    
            }
            g--;m--;p--;
            if(g>=0){
                    res+=travel[g];
            }
            if(m>=0){
                    res+=travel[m];
            }
            if(p>=0){
                    res+=travel[p];
            }
            return res;
            
    }
};