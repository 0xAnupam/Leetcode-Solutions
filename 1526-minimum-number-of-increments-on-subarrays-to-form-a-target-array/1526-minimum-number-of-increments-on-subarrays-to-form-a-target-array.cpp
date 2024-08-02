class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=target[0] , n=target.size();
        for(int i=0;i<n-1;i++){
            if(target[i+1]-target[i]>0)ans+=(target[i+1]-target[i]);
        }
        return ans;
    }
};