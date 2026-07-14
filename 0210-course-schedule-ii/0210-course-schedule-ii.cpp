// just do the topological sort then all done will get the perfect path for this 
// //DFS
// class Solution1 {
// public:
//     void dfs(vector<vector<int>>&adj,int u,vector<bool>&visited,stack<int>&st){
//         visited[u] = true;

//         for(int v:adj[u]){
//             if(!visited[v])
//                 dfs(adj,v,visited,st);
//         }
//         st.push(u);
//     }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         stack<int>st;
//         vector<bool>visited(numCourses,false);
//         vector<vector<int>>adj(numCourses);

//         //create the adcecency list

//         for(auto &x:prerequisites){
//             adj[x[1]].push_back(x[0]);
//         }

//         for(int i=0;i<numCourses;i++){
//             if(!visited[i]){
//                 dfs(adj,i,visited,st);
//             }
//         }

//         vector<int>res;

//         while(!st.empty()){
//             res.push_back(st.top());
//             st.pop();
//         }
//         return res;
//     }
// };


// bfs and khan's algo
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>res,inorder(numCourses);

        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }

        for(int i = 0;i<numCourses;i++){
            for(int v:adj[i]){
                inorder[v]++;
            }
        }
        queue<int>q;

        for(int i = 0;i<numCourses;i++){
            if(inorder[i]==0) q.push(i);
        }

        while(!q.empty()){
            int n = q.front();
            res.push_back(n);
            q.pop();

            for(int v:adj[n]){
                inorder[v]--;
                if(inorder[v]==0) q.push(v);
            }
        }
        if(res.size()==numCourses)
            return res;
        return {};
    }
};