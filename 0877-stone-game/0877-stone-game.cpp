class Solution {
public:
    vector<vector<int>> mem;
    int solve(int left, int right, vector<int>& piles) {
        if(left >= right) {
            return 0;
        }
        if(mem[left][right] != -1)
            return mem[left][right];
        int leftSum = piles[left] + solve(left + 1, right, piles);
        int rightSum = piles[right] + solve(left, right - 1, piles);

        return mem[left][right] = max(leftSum, rightSum);
    }

    bool stoneGame(vector<int>& piles) {
        mem.resize(piles.size(), vector<int>(piles.size(), -1));
        int AliceSum = solve(0, piles.size()-1, piles);
        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        return AliceSum > totalSum - AliceSum;
    }
};