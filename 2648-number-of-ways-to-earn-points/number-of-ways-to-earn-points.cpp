class Solution {
public:
const int MOD = 1e9 + 7;
    int f(int i, int target, vector<vector<int>>& types, vector<vector<int>>& dp) {
        if (target == 0) return 1;
        if (i >= types.size() || target < 0) return 0; 

        if (dp[i][target] != -1) return dp[i][target]; 

        int ways = 0;
        for (int j = 0; j <= types[i][0]; ++j) {
            int points = j * types[i][1];  
            if (points > target) break; 

            ways = (ways + f(i + 1, target - points, types, dp)) % MOD;  
        }

        return dp[i][target] = ways;
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<int>> dp(types.size(), vector<int>(target + 1, -1));
        return f(0, target, types, dp);
    }

};