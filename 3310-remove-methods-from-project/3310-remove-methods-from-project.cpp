class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for (auto &edge : invocations) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<bool> vis(n, false);

        function<void(int)> dfs = [&](int u) {
            vis[u] = true;

            for (int v : graph[u]) {
                if (!vis[v]) {
                    dfs(v);
                }
            }
        };

        dfs(k);

        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};