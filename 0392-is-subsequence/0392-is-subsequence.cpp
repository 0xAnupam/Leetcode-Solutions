class Solution
{
    public:
        bool isSubsequence(string s, string t)
        {
            int pointer = 0;
            int n = s.size();
            if (n == 0)
            {
                return 1;
            }
            for (auto &i: t)
            {
                if (i == s[pointer])
                {
                    pointer++;
                    if (pointer == n)
                    {
                        return 1;
                    }
                }
            }
            return 0;
        }
};