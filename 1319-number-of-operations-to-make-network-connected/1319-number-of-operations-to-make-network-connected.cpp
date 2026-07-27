class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x,int y,int &component){
        int parent_x  = find(x); 
        int parent_y = find(y);

        if(parent[parent_x]==parent[parent_y]) return;

        component--;
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_x]<rank[parent_y]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges < (n-1)) return -1;

        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        int component = n;
        for(auto &x:connections){
            int a = x[0];
            int b = x[1];
            int parent_a = find(a); 
            int parent_b = find(b);
            Union(a,b,component);
        }
        return component-1;
    }
};