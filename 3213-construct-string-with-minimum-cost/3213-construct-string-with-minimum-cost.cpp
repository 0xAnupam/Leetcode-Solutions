struct tries {
    tries* arr[26];
    int cost=INT_MAX;
};
void add(tries* head, string &s, int c) {
    tries* root = head;
    for (auto &i : s) {
        if (root->arr[i - 'a'] == nullptr) root->arr[i - 'a'] = new tries();
        root = root->arr[i - 'a'];
    }
    root->cost = min(root->cost, c);
}

const int N = 5e4 + 1;
int dp[N];
int f(string &s, int idx, int n, const tries* head) {
    if (idx == n) return 0;
    if (dp[idx] != -1) return dp[idx];
    int res = 1e9 + 1;
    int i = idx;
    const tries* current = head;
    while (i < n && current->arr[s[i] - 'a'] != nullptr) {
        current = current->arr[s[i] - 'a'];
        i++;
        if (current && current->cost != INT_MAX) {
            res = min(res, current->cost + f(s, i, n, head));
        }
    }
    return dp[idx] = res;
}

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        tries* head = new tries();
        int n = words.size();
        for (int i = 0; i < n; i++) {
            add(head, words[i], costs[i]);
        }
        fill(dp, dp + target.size() + 1, -1); 
        int result = f(target, 0, target.size(), head);
        delete head;  
        return result > (int)1e9  ? -1 : result;
    }
};