bool f(priority_queue<int> &pq,int &brick,int l,int extra){
       
        if(pq.size()<l){
                pq.push(-extra);
                return 1;
        }
        if(l==0){
                brick-=extra;
                return brick>=0;
        }
        int p=-pq.top();
       
        if(p<extra){
                brick-=p;
                pq.pop();
                pq.push(-extra);
                return brick>=0;
        }
        
        brick-=extra;
        return brick>=0;
}
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i=0,n=heights.size();
            while(i<n){
                    int p=heights[i];
                    while(i<n && heights[i]<=p){
                            p=heights[i++];
                    }
                  //  cout<<i<<' ';
                    if(i<n && f(pq,bricks,ladders,heights[i]-p)==0){
                            
                            return i-1;
                    }
                    
            }
            return i-1;
    }
};