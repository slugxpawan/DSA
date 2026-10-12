
class Solution {
private:
    int cnt;
    bool touchesBoundary;

    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        cnt++;

        // Check whether this land cell touches the boundary
        if (row == 0 || col == 0 ||
            row == n - 1 || col == m - 1) {
            touchesBoundary = true;
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 &&
                !vis[nrow][ncol]) {

                dfs(nrow, ncol, grid, vis);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && !vis[i][j]) {
                    cnt = 0;
                    touchesBoundary = false;
                    dfs(i, j, grid, vis);
                    if (!touchesBoundary) {
                        ans += cnt;
                    }
                }
            }
        }

        return ans;
    }
};

