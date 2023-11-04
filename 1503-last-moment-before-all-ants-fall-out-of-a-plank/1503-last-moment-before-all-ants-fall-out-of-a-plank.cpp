class Solution
{
    public:
        int getLastMoment(int n, vector<int> &left, vector<int> &right)
        {
            int res = 0;
            for (auto &i: right)
            {
                res = max(res, n - i);
            }
            for (auto &i: left)
            {
                res = max(res, i);
            }
            return res;
        }
};