class Solution {
public:

void solve(int src, unordered_map<int, list<pair<int,int>>>& adj, int& ans, vector<int>& visited){

    visited[src] = 1;   

    for(auto neighbour : adj[src]){
        int v = neighbour.first;
        int wt = neighbour.second;

        ans = min(ans, wt);   

        if(visited[v]) continue;    

        solve(v, adj, ans, visited);
    }

}

    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;

        unordered_map<int, list<pair<int,int>>> adj;
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int src = 1;

        vector<int> visited(n + 1, 0);

        solve(src, adj, ans, visited);

        return ans;
    }
};