class Solution {
public:
    int m,n;
    vector<vector<int>>mem;
    int solve(int i,int j,vector<vector<int>>& grid){
        if(i>=m || j>=n || grid[i][j]==1) return 0;
        //if(grid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(mem[i][j]!= -1) return mem[i][j];

        return mem[i][j] = solve(i+1,j,grid) + solve(i,j+1,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        mem.resize(m,vector<int>(n,-1));
        return solve(0,0,grid);

    }
};