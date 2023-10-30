class Solution
{
    public:
        vector<int> sortByBits(vector<int> &arr)
        {
            vector<pair<int, int>> x;
            for (auto &i: arr)
            {
                x.push_back({ __builtin_popcount(i),i });
            }
            sort(x.begin(), x.end());
            vector<int> res;
            for (auto &i: x)
            {
                res.push_back(i.second);
            }
            return res;
        }
};