// Travelling Salesman Problem
// Difficulty: HardAccuracy: 46.35%Submissions: 27K+Points: 8Average Time: 25m
// Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

// Examples:

// Input: cost = [[0, 111], [112, 0]]
// Output: 223
// Explanation: We can visit 0->1->0 and cost = 111 + 112.
// Input: cost = [[0, 1000, 5000], [5000, 0, 1000], [1000, 5000, 0]]
// Output: 3000
// Explanation: We can visit 0->1->2->0 and cost = 1000+1000+1000 = 3000
// Constraints:
// 1 <= cost.size() <= 20
// 1 <= cost[i][j] <= 103
class Solution {
public:
    int recurse(vector<vector<int>>& cost, int mask, vector<vector<int>>& dp, int ind, int n) {
        if (mask == 0) return cost[ind][0]; // Return to starting node 0

        if (dp[ind][mask] != -1) return dp[ind][mask];

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                ans = min(ans, cost[ind][i] + recurse(cost, mask ^ (1 << i), dp, i, n));
            }
        }

        return dp[ind][mask] = ans;
    }

    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
        int mask = (1 << n) - 1;
        mask ^= (1 << 0); // Remove starting node 0 from the mask
        return recurse(cost, mask, dp, 0, n);
    }
};
