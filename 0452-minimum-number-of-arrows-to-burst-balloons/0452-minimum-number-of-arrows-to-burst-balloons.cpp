int f(vector<vector<int>>& points,long long prev,int idx,int n){
        if(idx==n){
                return 0;
        }
        if(points[idx][0]>prev){
                return 1+f(points,points[idx][1],idx+1,n);
        }
        return f(points,min(1LL*points[idx][1],prev),idx+1,n);
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){
                if(a[0]==b[0]){
                        return a[1]>b[1];
                }
                return a[0]<b[0];
        });
            int n=points.size();
            return f(points,-1e18,0,n);
    }
};