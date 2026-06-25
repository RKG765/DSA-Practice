class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int res = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++){
                int count  = 0;
            for(int j = i;j<n;j++){
                int size = j-i+1;
                if(nums[j]==target) count++;
                if(count>(size/2)) res++;
            }
        }
        return res;
    }
};