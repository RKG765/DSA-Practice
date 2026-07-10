class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>>ansTable;


    int customUpperBound(vector<pair<int,int>>&arr,int num){
        int n = arr.size();

        int l = 0;
        int r = n-1;
        int result = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid].first <=num){
                result = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return result;
    }
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(begin(arr),end(arr));

        int nodeToindex[n];

        for(int i = 0;i<arr.size();i++){
            int pos = arr[i].second;
            nodeToindex[pos] = i;
        }

        //ansTable
        rows = n;
        cols = log2(n)+1;
        ansTable.assign(rows,vector<int>(cols,0));

        //filling the first column
        for(int node = 0;node<n;node++){
            int farthest_hop = customUpperBound(arr,arr[node].first+maxDiff);
            ansTable[node][0] = farthest_hop;
        }

        //filling remaining cols

        for(int j = 1;j<cols;j++){
            for(int node = 0;node<n;node++){
                ansTable[node][j] = ansTable[ ansTable[node][j-1] ] [j-1];
            }
        }

        vector<int>res;
        for(auto &x:queries){
            int u = x[0];
            int v = x[1];

            if(u==v){
                res.push_back(0);
                continue;
            }
            int a = nodeToindex[u];
            int b = nodeToindex[v];

            
            if(a>b) swap(a,b);

            int curr = a;
            int jumps = 0;

            for(int j = cols-1;j>=0;j--){
                if(ansTable[curr][j]<b){
                    curr = ansTable[curr][j];
                    jumps+=(1<<j);//pow(j,2);
                }
            }

            if(ansTable[curr][0]>=b){
                res.push_back(jumps+1);
            }
            else
                res.push_back(-1);
            


        }

        return res;

    }
};