class Solution {
public:
    // vector<vector<int>>dirs = {{1,0},{0,1}};
    vector<vector<int>>mem;
    int solve(int i,int j,int m,int n){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(mem[i][j]!=-1) return mem[i][j];
        //int res = 0;

        // for(auto &dir:dirs){
        //     int i_  = i+dir[0];
        //     int j_  = j+dir[1];

        //     res += solve(i_,j_,m,n);
        // }
        return mem[i][j] = solve(i+1,j,m,n)+solve(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        mem.resize(m,vector<int>(n,-1));
        return solve(0,0,m,n);
    }
};