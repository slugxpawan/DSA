
class Solution {
private:
    void dfs(int row, int col,
             vector<vector<int>>& image,
             vector<vector<int>>& ans,
             int delrow[], int delcol[],
             int iniColor, int newColor) {

        ans[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor &&
                ans[nrow][ncol] != newColor) {

                dfs(nrow, ncol, image, ans,
                    delrow, delcol, iniColor, newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int iniColor = image[sr][sc];

        vector<vector<int>> ans = image;

        if (iniColor == color) {
            return ans;
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        dfs(sr, sc, image, ans, delrow, delcol,
            iniColor, color);

        return ans;
    }
};

