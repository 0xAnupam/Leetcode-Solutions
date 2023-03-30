class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int res=special[0]-bottom;
            special.push_back(top+1);
            int n=special.size();
            for(int i=1;i<n;i++){
                    res=max(res,special[i]-special[i-1]-1);
            }
            return res;
    }
};