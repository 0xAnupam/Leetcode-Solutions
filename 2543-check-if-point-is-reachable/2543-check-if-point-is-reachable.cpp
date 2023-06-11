map<pair<int,int>,int> mp;
bool f(int x,int y){
        if(mp.find({x,y})!=mp.end()){
                return mp[{x,y}];
        }
        if(x==1 && y==1){
                return 1;
        }
        if(min(x,y)<1){
                return 0;
        }
        
        bool flag=min(x,y)==1;
        if(x%2==0){
                flag|=f(x/2,y);
        }
        if(y%2==0){
                flag|=f(x,y/2);
        }if(x!=x%y){
                flag|=f(x%y,y);
        }
        if(y!=y%x){
                flag|=f(x,y%x);
        }
        return mp[{x,y}]=flag;
        
}
class Solution {
public:
    bool isReachable(int targetX, int targetY) {
                mp.clear();
            return f(targetX,targetY);
    }
};