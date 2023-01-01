class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x=0,y=0;
            for(auto &i:arr1){
                    x^=i;
            }
            for(auto &i:arr2){
                    y^=i;
            }
            return (x&y);
    }
};