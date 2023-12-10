int omk(vector<int> &arr){
    int a=1,mod=arr[3];
    for(int i=1;i<=arr[1];i++){
        a*=arr[0];
        a%=10;
    }
    int res=1;
    for(int i=1;i<=arr[2];i++){
        res*=a;
        res%=mod;
    }
    return res;
    
    
}
class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int n=variables.size();
        vector<int> r;
        for(int i=0;i<n;i++){
            if(omk(variables[i])==target)r.emplace_back(i);
        }
        return r;
    }
};