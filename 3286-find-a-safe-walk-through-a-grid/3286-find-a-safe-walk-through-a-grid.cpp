class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        deque<pair<int,int>>dq;

        vector<vector<int>>result(m,vector<int>(n,1e7));

        result[0][0] = grid[0][0]; 

        dq.push_front({0,0});

        while(!dq.empty()){
            auto [row,col] = dq.front();
            dq.pop_front();

            for(auto dir:directions){ //directions is 2d array for top bottom left right
                int nrow = row+dir[0];
                int ncol = col+dir[1];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                if(result[nrow][ncol]>result[row][col]+grid[nrow][ncol]){
                    result[nrow][ncol] = result[row][col]+grid[nrow][ncol];
                    if(grid[nrow][ncol]==0){
                        dq.push_front({nrow,ncol});
                    }
                    else{
                        dq.push_back({nrow,ncol});
                    }
                }
            }
            }
        }
        int x = result[m-1][n-1];

        return (health-x)>0;

    }
};