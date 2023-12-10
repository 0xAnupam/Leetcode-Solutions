class Solution{
    public:
        vector<vector < int>> transpose(vector<vector < int>> &matrix){
            int n = matrix.size(), m = matrix[0].size();
            if (n == m){
                for (int i = 0; i < n; i++){
                    for (int j = i + 1; j < n; j++){
                        swap(matrix[i][j], matrix[j][i]);
                    }
                }
                return matrix;
            }

            vector<vector < int>> x;
            for (int i = 0; i < m; i++){
                vector<int> y;
                for (int j = 0; j < n; j++){
                    y.push_back(matrix[j][i]);
                }
                x.push_back(y);
            }
            return x;
        }
};