class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Step 1: Multi-Source BFS
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int max_dist = 0;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    max_dist = max(max_dist, dist[nr][nc]);
                    q.push({nr, nc});
                }
            }
        }
        
        // Step 2: Bucket cells by their safeness distance
        vector<vector<pair<int, int>>> buckets(max_dist + 1);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                buckets[dist[r][c]].push_back({r, c});
            }
        }
        
        // Step 3: Union-Find from highest safeness down to 0
        DSU dsu(n * n);
        vector<vector<bool>> active(n, vector<bool>(n, false));
        
        for (int d = max_dist; d >= 0; --d) {
            for (auto& [r, c] : buckets[d]) {
                active[r][c] = true;
                
                // Convert 2D coordinates to a 1D index for the DSU
                int idx1 = r * n + c;
                
                // Connect with adjacent active cells
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && active[nr][nc]) {
                        int idx2 = nr * n + nc;
                        dsu.unite(idx1, idx2);
                    }
                }
            }
            
            // If start and end cells are active AND connected, we found our optimal path
            if (active[0][0] && active[n - 1][n - 1] && dsu.connected(0, n * n - 1)) {
                return d;
            }
        }
        
        return 0;
    }
};