class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
            long long res=0;
            for(auto &i:piles){
                    q.push(i);
            }
            while(q.size() && k--){
                    auto p=q.top();
                    q.pop();
                    p=(p+1)/2;
                    if(p<2){
                            res+=p;
                    }
                    else{
                            q.push(p);
                    }
            }
            while(q.size()){
                    res+=q.top();
                    q.pop();
            }
            return res;
    }
};