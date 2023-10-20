class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
            int nxt[n];
            stack<pair<int,int>> s;
            s.push({INT_MAX,n});
            for(int i=n-1;i>=0;i--){
                    while(s.top().first<heights[i]){
                            s.pop();
                    }
                    nxt[i]=s.top().second;
                    s.push({heights[i],i});
            }
            
            
            vector<int> res(n);
            for(int i=0;i<n;i++){
                    
                    int j=nxt[i],cnt=0,p=0;
                    if(i<n-1 && heights[i+1]<heights[i]){
                            j=i+1;
                    }
                    while(j<n && heights[i]>p){
                            p=heights[j];
                            j=nxt[j];
                            cnt++;
                            
                    }
                    res[i]=cnt;
            }
            return res;
    }
};