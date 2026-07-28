class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x==parent_y) return;

        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_x]<rank[parent_y]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(auto &x:edges){
            int u = x[0];
            int v = x[1];
            Union(u,v);
        }
        unordered_map<int,int>freq;
        for(int i = 0;i<n;i++){
            freq[find(i)]++;
        }

        long long res = 0;
        long long remain_node = n;
        for(auto &x:freq){
            int size = x.second;
            res+= size * (remain_node - size);
            remain_node -= size;
        }
        return res;
    }
};