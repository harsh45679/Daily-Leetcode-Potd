class Solution {
public:
    bool valid(int x, int y, vector<vector<int>>& grid) {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
            return true;
        }
        return false;
    }

    bool solve(vector<vector<int>>& grid,
               vector<vector<bool>>& vis,
               vector<vector<int>>& best,
               int x, int y,
               int n, int m,
               int health) {

        if (grid[x][y] == 1) {
            health--;
        }

        if (health <= 0) {
            return false;
        }

        if (x == n - 1 && y == m - 1) {
            return true;
        }

        // DP Pruning
        if (best[x][y] >= health) {
            return false;
        }

        best[x][y] = health;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};

        vis[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (valid(newx, newy, grid) && !vis[newx][newy]) {
                if (solve(grid, vis, best, newx, newy, n, m, health))
                    return true;
            }
        }

        vis[x][y] = false;
        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> best(n, vector<int>(m, -1));

        return solve(grid, vis, best, 0, 0, n, m, health);
    }
};