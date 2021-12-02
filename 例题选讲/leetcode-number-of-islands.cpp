// 题目：https://leetcode-cn.com/problems/number-of-islands/
// 直接使用DFS进行染色标记即可

class Solution {
   public:
    void dfs(vector<vector<char>>& grid, int raw, int collumn) {
        grid[raw][collumn] = '0';
        if (raw - 1 >= 0 && grid[raw - 1][collumn] == '1')
            dfs(grid, raw - 1, collumn);
        if (raw + 1 < grid.size() && grid[raw + 1][collumn] == '1')
            dfs(grid, raw + 1, collumn);
        if (collumn - 1 >= 0 && grid[raw][collumn - 1] == '1')
            dfs(grid, raw, collumn - 1);
        if (collumn + 1 < grid[raw].size() && grid[raw][collumn + 1] == '1')
            dfs(grid, raw, collumn + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int ans = 0;
        for (int raw = 0; raw < grid.size(); ++raw) {
            for (int collumn = 0; collumn < grid[raw].size(); ++collumn) {
                if (grid[raw][collumn] == '1') {
                    ans++;
                    dfs(grid, raw, collumn);
                }
            }
        }
        return ans;
    }
};