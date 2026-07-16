class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        //vector<int>prefixGcd;
        int n = nums.size();

        int maxEle = 0;
        for(int i = 0;i<n;i++){
            maxEle = max(maxEle,nums[i]);

            // prefixGcd.push_back(gcd(nums[i],maxEle));
            // instead you can also update the value in the same place 
            nums[i] = gcd(maxEle,nums[i]);
            // it will reduce the s(0) = o(1) instead of o(n)
        }

        // sort(begin(prefixGcd),end(prefixGcd));
        sort(begin(nums),end(nums));
        int s = 0;
        // int e = prefixGcd.size()-1;
        int e = nums.size()-1;
        long long res = 0;
        while(s<e){
            // long long curGcd = gcd(prefixGcd[s],prefixGcd[e]);
            // res += curGcd;
            res += gcd(nums[s],nums[e]);
            s++;
            e--;
        }
        return res;
    }
};