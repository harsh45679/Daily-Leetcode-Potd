class Solution {
public:
    bool valid(int x, int y, vector<vector<char>>& question) {
        return (x >= 0 && x < question.size() &&
                y >= 0 && y < question[0].size() &&
                question[x][y] != 'X');
    }

    // returns {maxScore, count}; maxScore == -1 means unreachable
    pair<int,int> solve(int x, int y, int n, int m,
                         vector<vector<char>>& question,
                         vector<vector<pair<int,int>>>& memo,
                         vector<vector<bool>>& vis) {

        if (x == 0 && y == 0) {
            return {0, 1};
        }

        if (memo[x][y].first != -2)   // -2 = not computed yet
            return memo[x][y];

        vis[x][y] = true;

        int dx[3] = {-1, 0, -1};
        int dy[3] = {0, -1, -1};

        int maxsum = -1;
        long long count = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < 3; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (valid(newx, newy, question) && !vis[newx][newy]) {
                auto res = solve(newx, newy, n, m, question, memo, vis);
                if (res.first == -1) continue;

                int val = 0;
                if (isdigit(question[newx][newy]))
                    val = question[newx][newy] - '0';

                int newsum = res.first + val;
                if (newsum > maxsum) {
                    maxsum = newsum;
                    count = res.second;
                } else if (newsum == maxsum) {
                    count = (count + res.second) % MOD;
                }
            }
        }

        vis[x][y] = false;

        memo[x][y] = {maxsum, (int)count};
        return memo[x][y];
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<char>> question(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                question[i][j] = board[i][j];

        vector<vector<pair<int,int>>> memo(n, vector<pair<int,int>>(m, {-2, -2}));
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        auto res = solve(n - 1, m - 1, n, m, question, memo, vis);

        if (res.first == -1)
            return {0, 0};

        return {res.first, res.second};
    }
};