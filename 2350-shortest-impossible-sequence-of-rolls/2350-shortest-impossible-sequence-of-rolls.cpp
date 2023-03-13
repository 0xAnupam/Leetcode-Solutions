class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
       int res=1;
        set<int> s;
            for(auto &i:rolls){
                    s.insert(i);
                    if(s.size()==k){
                            res++;
                            s.clear();
                    }
            }
            return res;
    }
};