class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int x=0;
            for(auto &i:pref){
                    i^=x;
                    x^=i;
            }
            return pref;
    }
};