bool f(vector<int> &time,long long k,long long m){
        long long res=0;
        for(auto &i:time){
                res+=m/i;
                if(res>=k){
                        return 1;
                }
                else if(i>m){
                        return 0;
                }
        }
        return 0;
}
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1,h=1e15,m;
            sort(time.begin(),time.end());
            while(l<=h){
                    m=l+(h-l)/2;
                    if(f(time,totalTrips,m)){
                            h=m-1;
                    }
                    else{
                            l=m+1;
                    }
            }
            return l;
    }
};