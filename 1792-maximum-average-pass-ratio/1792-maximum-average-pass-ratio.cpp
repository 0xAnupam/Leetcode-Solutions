
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       auto cmp = [](pair<long long,long long> a, pair<long long,long long> b) { 
               
            return (a.second-a.first)*b.second*(b.second+1)<(b.second-b.first)*a.second*(a.second+1);
       };

    // create a priority queue that uses the lambda expression as the comparison function
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, decltype(cmp)> pq(cmp);
            for(auto &i:classes){
                    pq.push({i[0],i[1]});
            }
            while(extraStudents--){
                    auto p=pq.top();
                    
                    pq.pop();
                    pq.push({p.first+1,p.second+1});
            }
            long double res=0;
            while(pq.size()){
                    long double a=pq.top().first,b=pq.top().second;
                   // cout<<a<<" "<<b<<'\n';
                    pq.pop();
                    res+=(a/b);
            }
            long double n=classes.size();
            res/=n;
            return res;
    }
};