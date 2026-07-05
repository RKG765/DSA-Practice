using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD = 1e9 + 7;
        
        // dp[r][c] stores the maximum score to reach cell (r, c)
        // Initialize with -1 to represent unreachable cells
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // ways[r][c] stores the number of paths to reach cell (r, c) with max score
        vector<vector<int>> ways(n, vector<int>(n, 0));
        
        // Base case: Start at bottom-right (n-1, n-1)
        dp[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;
        
        // Directions we can come FROM: Down (1, 0), Right (0, 1), Diagonal (1, 1)
        int dirs[3][2] = {{1, 0}, {0, 1}, {1, 1}};
        
        // Iterate backwards from bottom-right to top-left
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                
                // Skip the starting cell (already initialized) and obstacles
                if (board[r][c] == 'X' || (r == n - 1 && c == n - 1)) {
                    continue;
                }
                
                int max_prev_score = -1;
                int current_ways = 0;
                
                // Check the three adjacent cells we could have moved from
                for (auto& dir : dirs) {
                    int prev_r = r + dir[0];
                    int prev_c = c + dir[1];
                    
                    // If the previous cell is within bounds and reachable
                    if (prev_r < n && prev_c < n && dp[prev_r][prev_c] != -1) {
                        
                        // If we found a strictly better path
                        if (dp[prev_r][prev_c] > max_prev_score) {
                            max_prev_score = dp[prev_r][prev_c];
                            current_ways = ways[prev_r][prev_c];
                        } 
                        // If we found another path tying for the max score
                        else if (dp[prev_r][prev_c] == max_prev_score) {
                            current_ways = (current_ways + ways[prev_r][prev_c]) % MOD;
                        }
                    }
                }
                
                // If this cell is completely unreachable, leave as -1
                if (max_prev_score != -1) {
                    // 'E' gives 0 points, otherwise convert char to integer
                    int val = (board[r][c] == 'E') ? 0 : (board[r][c] - '0');
                    dp[r][c] = max_prev_score + val;
                    ways[r][c] = current_ways;
                }
            }
        }
        
        // If the destination 'E' is unreachable, return [0, 0]
        if (dp[0][0] == -1) {
            return {0, 0};
        }
        
        return {dp[0][0], ways[0][0]};
    }
};