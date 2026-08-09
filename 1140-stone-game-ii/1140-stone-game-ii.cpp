class Solution {
public:
    // now memoization
    vector<vector<int>> mem;
    int solve(int idx, int m, vector<int>& suffixSum, int n) {
        if (idx >= n)
            return 0;

        if (idx + 2 * m >= n)
            return suffixSum[idx];
        if (mem[idx][m] != -1)
            return mem[idx][m];
        int maxSum = 0;

        for (int X = 1; X <= 2 * m; X++) {
            int newIdx = idx + X;
            int newM = max(X, m);

            // bob will choose
            int bob = solve(newIdx, newM, suffixSum, n);

            int newMax = suffixSum[idx] - bob;

            maxSum = max(maxSum, newMax);
        }
        return mem[idx][m] = maxSum;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        mem.resize(n + 1, vector<int>(n + 1, -1));
        return solve(0, 1, suffixSum, n);
    }
};