class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long>prefixGcd;
        int n = nums.size();
        if(n==1) return 0;
        int maxEle = 0;
        for(int i = 0;i<n;i++){
            maxEle = max(maxEle,nums[i]);

            prefixGcd.push_back(gcd(nums[i],maxEle));
        }

        sort(begin(prefixGcd),end(prefixGcd));
        long long m = prefixGcd.size();
        long long s = 0;
        long long e = m-1;
        long long res = gcd(prefixGcd[0],prefixGcd[e]);
        s++;
        e--;
        while(s<e){
            long long curGcd = gcd(prefixGcd[s],prefixGcd[e]);
            res += curGcd;
            s++;
            e--;
        }
        return res;
    }
};