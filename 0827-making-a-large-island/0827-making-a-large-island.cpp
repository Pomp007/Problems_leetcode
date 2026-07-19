class Solution {
public:
    int n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>>& grid, int id, int i, int j) {
        grid[i][j] = id;
        int sum = 1;

        for (int k = 0; k < 4; k++) {
            int nrow = i + dr[k];
            int ncol = j + dc[k];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < n &&
                grid[nrow][ncol] == 1) {

                sum += dfs(grid, id, nrow, ncol);
            }
        }

        return sum;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();

        int id = 2;
        unordered_map<int, int> mpp;
        bool hasZero = false;

        // Label each island and store its area
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    int size = dfs(grid, id, i, j);
                    mpp[id] = size;
                    id++;
                }

                if (grid[i][j] == 0)
                    hasZero = true;
            }
        }

        // Grid is all 1's
        if (!hasZero)
            return n * n;

        int ans = 0;

        // Try converting every 0 into 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {

                    unordered_set<int> unique_id;

                    for (int k = 0; k < 4; k++) {
                        int nrow = i + dr[k];
                        int ncol = j + dc[k];

                        if (nrow >= 0 && nrow < n &&
                            ncol >= 0 && ncol < n &&
                            grid[nrow][ncol] != 0) {

                            unique_id.insert(grid[nrow][ncol]);
                        }
                    }

                    int overallArea = 1;

                    for (auto it : unique_id) {
                        overallArea += mpp[it];
                    }

                    ans = max(ans, overallArea);
                }
            }
        }

        return ans;
    }
};