class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum=0;
            for(auto &i:target){
                    pq.push(i);
                    sum+=i;
            }
            while(pq.size() && pq.top()>1){
                    auto p=pq.top();
                    pq.pop();
                    long long t=sum-p;
                    if(t>=p)
                    {
                            return 0;
                    }
                    if(t==0){
                            return 0;
                    }
                    int gg=p/t;gg=max(1,gg-1);
                    pq.push(p-gg*t);
                    sum-=t*gg;
            }
            return 1;
    }
};