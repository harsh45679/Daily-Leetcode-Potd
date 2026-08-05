class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        unordered_map<int, list<int>> adj;

        for (int i = 0; i < invocations.size(); i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);
        }

      
        queue<int> q;
        vector<bool> vis(n, false);
        vector<int> suspicious;

        q.push(k);
        vis[k] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            suspicious.push_back(node);

            for (auto neighbour : adj[node]) {
                if (!vis[neighbour]) {
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(i);
        }

       
        for (auto node : suspicious) {
            st.erase(node);
        }

        
        for (auto edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (st.count(u) && vis[v]) {
                vector<int> all;
                for (int i = 0; i < n; i++) {
                    all.push_back(i);
                }
                return all;
            }
        }

        vector<int> ans;
        for (auto node : st) {
            ans.push_back(node);
        }

        return ans;
    }
};