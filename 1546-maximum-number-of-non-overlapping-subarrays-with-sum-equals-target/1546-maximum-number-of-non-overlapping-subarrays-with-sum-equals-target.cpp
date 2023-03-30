class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        set<int> s;
        s.insert(0);
        int res=0,sum=0;
            for(auto &i:nums){
                    sum+=i;
                    if(s.find(sum-target)!=s.end()){
                            s.clear();
                            res++;
                            s.insert(0);
                            sum=0;
                    }
                    else{
                            s.insert(sum);
                    }
            }
            return res;
    }
};