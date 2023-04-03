class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
            vector<int> res;
        for(auto &i:queries){
                vector<int> a,b;
                while(i[0]){
                        a.push_back(i[0]);
                        i[0]>>=1;
                }
                while(i[1]){
                        b.push_back(i[1]);
                        i[1]>>=1;
                }
                int I=0,j=0;
                while(a[I]!=b[j]){
                        while(a[I]>b[j]){
                                I++;
                        }
                        while(b[j]>a[I]){
                                j++;
                        }
                }
                
                res.push_back(I+j+1);
                
        }
            return res;
    }
};