class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<bool> arr(n+1,0);
            for(auto &i:target){
                    arr[i]=1;
            }
            vector<string> res;
            int j=target[target.size()-1];
            string a="Push",b="Pop";
            for(int i=1;i<=j;i++){
                    res.emplace_back(a);
                    if(arr[i]==0){
                            res.emplace_back(b);
                    }
            }
            return res;
    }
};