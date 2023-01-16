int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
            int l[n],r[n];
           stack<pair<int,int>> s;
            for(int i=0;i<n;i++){
                    int p=1;
                    while(s.size() && s.top().first>=heights[i]){
                            p+=s.top().second;
                            s.pop();
                    }
                    l[i]=p;
                    s.push({heights[i],p});
            }while(s.size()){s.pop();}
            for(int i=n-1;i>=0;i--){
                    int p=1;
                    while(s.size() && s.top().first>=heights[i]){
                            p+=s.top().second;
                            s.pop();
                    }
                    r[i]=p;
                    s.push({heights[i],p});
            }
            int res=0;
            for(auto i=0;i<n;i++){
                    res=max(res,heights[i]*(l[i]+r[i]-1));
            }
            return res;
            
    }
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
            int r=matrix.size(),c=matrix[0].size(),res=0;
            vector<vector<int>> ans(r,vector<int>(c));
            for(int i=0;i<r;i++){
                    int sum=0;
                    for(int j=0;j<c;j++){
                            sum=(matrix[i][j]-'0')+sum*(matrix[i][j]-'0');
                            ans[i][j]=sum;
                    }
            }
            for(int j=0;j<c;j++){
                    vector<int> h;
                    for(int i=0;i<r;i++){
                            h.emplace_back(ans[i][j]);
                    }
                    res=max(res,largestRectangleArea(h));
            }
            
            return res;
    }
};