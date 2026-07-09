class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>res;
        vector<int>component(n,0);
        int currComp = 0;
        for(int i=1;i<n;i++){  //n
            if((nums[i]-nums[i-1])>maxDiff){
                currComp++;
            }
            component[i] = currComp;
        }


        for(auto &q:queries){ //q.length = Q
            int u = q[0];
            int v = q[1];

            if(component[u]==component[v]){
                res.push_back(1);
            }
            else res.push_back(0);
        }
        return res;
    }
};