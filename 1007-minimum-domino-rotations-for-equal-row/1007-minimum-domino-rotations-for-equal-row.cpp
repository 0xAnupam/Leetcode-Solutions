int mini(vector<int>&arr,int k){
        int res=0;
        for(auto &i:arr){
                if(i!=k){
                        res++;
                }
        }
        return res;
}
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size(),res=n+1;
            for(int i=1;i<=6;i++){
                    int j=0;
                    while(j<n && (tops[j]==i || bottoms[j]==i )){
                            j++;
                    }
                    if(j==n){
                            res=min({res,mini(tops,i),mini(bottoms,i)});
                    }
            }
            return res == n+1 ? -1:res;
    }
};