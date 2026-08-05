class Solution {
public:
    void dfs(int u, vector<bool>& sus, vector<vector<int>>& adj) {
        sus[u] = true;

        for (int v : adj[u]) {
            if (!sus[v]) {
                dfs(v, sus, adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<bool> sus(n, false);
        vector<vector<int>> adj(n);
        for (auto& x : invocations) {
            adj[x[0]].push_back(x[1]);
        }

        // finding all the sus by starting only from k

        dfs(k, sus, adj);

        // finding weather a node invokes the sus node

        bool notRemove = false;

        for (auto& x : invocations) {
            int u = x[0];
            int v = x[1];
            if (!sus[u] && sus[v]) {
                notRemove = 1;
            }
        }

        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (notRemove || !sus[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};