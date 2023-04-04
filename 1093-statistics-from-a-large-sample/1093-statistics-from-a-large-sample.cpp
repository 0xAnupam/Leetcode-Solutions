long double m_finder(vector<pair<int,long long>> &v,int n ){
        int sum=0;
        for(auto &i:v){
                
                if(i.second>=n){
                        return i.first*1.00;
                }
        }
        return 0;
}
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int a=-1,b,c=0,mode,gg=0;
            long double cnt=0,n=0;
            vector<pair<int,long long>> v;
            for(long long i=0;i<256;i++){
                    if(count[i]){
                            if(a==-1){
                                    a=i;
                            }
                            if(count[i]>c){
                                    c=count[i];
                                    mode=i;
                            }
                            b=i;
                            cnt+=(i*count[i]);
                            n++;
                            gg+=count[i];
                            v.push_back({i,gg});
                    }
            }
             double mean=cnt;
            mean/=gg;
             double median;
            if(gg&1){
                    median=m_finder(v,gg/2+1);
            }
            else{
                    median=m_finder(v,gg/2)+m_finder(v,gg/2+1);
                    median/=2;
            }
            return {double(a),double(b),mean,median,(double)mode};
    }
};