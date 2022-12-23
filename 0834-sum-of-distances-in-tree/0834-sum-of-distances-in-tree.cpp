class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> ans(N);
        vector<int> count(N);
        vector<vector<int>> adj(N);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1, adj, count, ans);
        dfs2(0, -1, adj, count, ans);
        return ans;
    }

private:
    void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& count, vector<int>& ans) {
        count[u] = 1;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, adj, count, ans);
            count[u] += count[v];
            ans[u] += ans[v] + count[v];
        }
    }

    void dfs2(int u, int p, vector<vector<int>>& adj, vector<int>& count, vector<int>& ans) {
        for (int v : adj[u]) {
            if (v == p) continue;
            ans[v] = ans[u] - count[v] + (count.size() - count[v]);
            dfs2(v, u, adj, count, ans);
        }
    }
};
