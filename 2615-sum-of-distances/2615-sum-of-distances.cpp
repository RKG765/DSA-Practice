class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return {0};

        unordered_map<int,vector<long long>>mp;
        // nums[i] --> on whihever index which postion
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<long long>res(n,0);
        for(auto &[val,pos]:mp){
            long long  m = pos.size();
            long long totalSum = 0;
            for(long long &ele:pos){
                totalSum+=ele;
            }
            //have total sum
            // find left sum
            long long leftSum = 0;
            for(int i =0;i<m;i++){
                long long idx = pos[i];
                long long rightSum = totalSum - leftSum -idx;

                // we had to do is 
                long long leftDist = (i* idx) - leftSum;
                long long rightDist = rightSum - ((m-i-1)*idx);

                res[idx] = rightDist + leftDist;
                leftSum += idx;
            }
        }
        return res;
    }
};