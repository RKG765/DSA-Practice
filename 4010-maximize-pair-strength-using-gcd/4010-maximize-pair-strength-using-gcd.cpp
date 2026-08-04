class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long num=0;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                long long t = 1ll *gcd(nums[i],nums[j]);
                long long temp = (1ll * nums[i]*nums[j]) / (t*t);
                num = max(num,temp); 
            }
        }
        return num;
    }
};