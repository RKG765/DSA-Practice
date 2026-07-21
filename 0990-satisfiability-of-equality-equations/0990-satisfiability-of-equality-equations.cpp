class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a,int b){
        int parent_a = find(a);
        int parent_b = find(b);

        if(parent[parent_a]==parent[parent_b]) return;

        if(rank[parent_a]>rank[parent_b]){
            parent[parent_b] = parent_a;
        }
        else if(rank[parent_a]<rank[parent_b]){
            parent[parent_a] = parent_b;
        }else{
            parent[parent_a] = parent_b;
            rank[parent_b]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
        for(auto &s:equations){ // found the == cases added it to the union
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        }
        // find the != cases chec the valadity
        for(auto &s:equations){
            if(s[1]=='!'){
                int parent_x = find(s[0]-'a');
                int parent_y = find(s[3]-'a');

                if(parent[parent_x]==parent[parent_y]){
                    return false;
                }
            }
        }

        return true;
    }
};