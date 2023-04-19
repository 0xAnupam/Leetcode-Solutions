int time(string &s){
        int a=stoi(s.substr(0,2)),b=stoi(s.substr(3));
        return 60*a+b;
}
int diff(string &a,string &b){
        int X=time(a),Y=time(b);
        X=abs(X-Y);
        return min(X,abs(24*60-X));
}
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
            int n=timePoints.size();
            int res=1e5;
            for(int i=0;i<n-1;i++){
                    res=min(res,diff(timePoints[i],timePoints[i+1]));
            }
            res=min(res,diff(timePoints[0],timePoints[n-1]));
            return res;
    }
};