bool gg(vector<int>& bloomDay, int m, int k,int mid){
        int i=0,n=bloomDay.size();
        while(i<n){
                if(bloomDay[i]>mid){
                        i++;
                        continue;
                }
                int cnt=0;
                while(i<n && bloomDay[i]<=mid){
                        cnt++;
                        i++;
                }
                cnt/=k;
                if(cnt>=m)return 1;
                m-=cnt;
        }
        return 0;
}
class Solution {
public:
    int minDays(vector<int>& bloomDay, int M, int k) {
            int l=0,h=*max_element(bloomDay.begin(),bloomDay.end()),m;
            int rng=h;
            while(l<=h){
                    m=(l+h)/2;
                    if(gg(bloomDay,M,k,m)){
                            h=m-1;
                    }
                    else{
                            l=m+1;
                    }
            }
            return l<=rng ? l : -1;
    }
};