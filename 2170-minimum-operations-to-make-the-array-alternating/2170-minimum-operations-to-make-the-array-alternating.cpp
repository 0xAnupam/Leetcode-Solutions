class Solution {
public:
    int minimumOperations(vector<int>& nums) {
            int n=nums.size();
            map<int,int> a,b;
            int x=0,y=0;
            for(int i=0;i<n;i++){
                    if(i&1){
                          b[nums[i]]++;
                          x++;  
                    }
                    else{
                            a[nums[i]]++;
                            y++;
                    }
            }
            multiset<int> mp;
            mp.insert(0);
            for(auto &i:b){
                    mp.insert(i.second);
            }
            int res=n;
            for(auto &i:a){
                    int p=y-i.second;
                    int l=b[i.first];
                    if(l){
                            mp.erase(mp.find(l));
                    }
                    res=min(res,p+x-*mp.rbegin());
                    if(l){
                            mp.insert(l);
                    }
                    
            }
            return res;
        
    }
};