class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& component) {
        vis[node] = 1;
        component.push_back(node);

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        // Find every connected component
        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                vector<int> component;
                dfs(i, adj, vis, component);

                int sz = component.size();
                bool complete = true;

                // Every node must connect to all other nodes
                for (int node : component) {
                    if (adj[node].size() != sz - 1) {
                        complete = false;
                        break;
                    }
                }

                if (complete)
                    ans++;
            }
        }

        return ans;
    }
};