class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {

        int a = 0; int b = 0; int c = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i < grid.size()-1 && j < grid[0].size()-1 && grid[i][j] < grid[i+1][j+1]) {
            a = 1 + f(i+1,j+1, grid,dp);
        }
        if(j < grid[0].size()-1 && grid[i][j] < grid[i][j+1]) {
            b = 1 + f(i,j+1, grid,dp);
        }
        if(i > 0 && j < grid[0].size()-1 && grid[i][j] < grid[i-1][j+1]) {
            c = 1 + f(i-1,j+1, grid,dp);
        }
        return dp[i][j] = max({a,b,c});

    }

    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        for(int i = 0;i<grid.size();i++) {
            ans = max(ans, f(i,0,grid,dp));
        }
        return ans;
    }
};