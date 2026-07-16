class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long>prefixGcd;
        int n = nums.size();

        int maxEle = 0;
        for(int i = 0;i<n;i++){
            maxEle = max(maxEle,nums[i]);

            prefixGcd.push_back(gcd(nums[i],maxEle));
        }

        sort(begin(prefixGcd),end(prefixGcd));
        long long s = 0;
        long long e = prefixGcd.size()-1;
        long long res = 0;
        while(s<e){
            long long curGcd = gcd(prefixGcd[s],prefixGcd[e]);
            res += curGcd;
            s++;
            e--;
        }
        return res;
    }
};