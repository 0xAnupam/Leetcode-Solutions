class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        set<int> b;
            int n=flips.size(),res=0;
            vector<int> arr(n+1,0);
            
            for(auto &i:flips){
                    if(arr[i]==0){
                            b.insert(i);
                            arr[i]=0;
                    }
                    else{
                            b.erase(i);
                            arr[i]=1;
                    }
                    if(b.size() && *(b.rbegin())==b.size()){
                            res++;
                    }
                    
            }
            return res;
            
    }
};