class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>res(m,vector<int>(n));

        while(k--){
            for(int i = 0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(j==n-1 && i<m-1){ // ever row last ele
                        res[i+1][0] = grid[i][j];
                    }
                    if(i==m-1 && j==n-1){ // last element
                        res[0][0] = grid[m-1][n-1];
                    }
                    if(i<=m-1 && j<n-1)
                        res[i][j+1] = grid[i][j];
                }
            }
            grid = res;
        }
        return grid;
    }
};