const int N=1e5;
bool covers(map<int,int> &mp,int k){
        return mp.size()==k;
}
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
            
        vector<vector<int>> mat(200001,vector<int>());
            int k=0;
            for(auto &j:nums){
                    k++;
                    for(auto &i:j){
                        mat[i+N].push_back(k);    
                    }
            }
            int n=k,a=0,b=1e9;
            int i=0,j=0,m=2e5+1;
            map<int,int> mp;
            while(i<m){
                    while(i<m && covers(mp,k)==false){
                            for(auto &c:mat[i]){
                                    mp[c]++;
                            }
                            i++;
                    }
                    while(j<=i && covers(mp,k)==true){
                            if(i-j<b-a){
                                    b=i;
                                    a=j;
                            }
                            for(auto &c:mat[j]){
                                    if(mp[c]==1){
                                            mp.erase(c);
                                    }
                                    else{
                                            mp[c]--;
                                    }
                            }
                            j++;
                    }
                   
            }
            return {{a-N},{b-N-1}};
            
    }
};