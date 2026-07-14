class Solution {
public:
    int mod = 1e9+7;

    vector<vector<vector<int>>>mem;
    int solve(vector<int>&nums,int i,int first,int second){
        int n = nums.size();
        if(i==n){
            if(first != 0 && second!=0 && first==second)
                return 1;
            else return 0;
        }
        if(mem[i][first][second]!=-1){
            return mem[i][first][second];
        }

        long long take1 = solve(nums,i+1,gcd(first,nums[i]),second);
        long long take2 = solve(nums,i+1,first,gcd(second,nums[i]));
        long long  skip = solve(nums,i+1,first,second);
        return mem[i][first][second] = (take1+take2+skip)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        int maxEle = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            maxEle = max(maxEle,nums[i]);
        }
        mem.assign(n,vector<vector<int>>(maxEle+1,vector<int>(maxEle+1,-1)));
        return solve(nums,0,0,0);
    }
};