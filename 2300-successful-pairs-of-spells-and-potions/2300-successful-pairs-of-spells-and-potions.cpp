class Solution
{
    public:
        vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
        {
            sort(potions.begin(), potions.end());
            vector<int> res;
            for (auto &i: spells)
            {
                long long l = 0, h = potions.size() - 1, m;
                while (l <= h)
                {
                    m = l + (h - l) / 2;
                    long long k = i;
                    if (potions[m] *k >= success)
                    {
                        h = m - 1;
                    }
                    else
                    {
                        l = m + 1;
                    }
                }
                res.push_back(potions.size() - l);
            }
            return res;
        }
};