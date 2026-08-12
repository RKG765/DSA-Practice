class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int res = 0;
        unordered_map<int,int>freq;

        for(int right = 0;right<n;right++){
            freq[nums[right]]++;

            while(freq[nums[right]]>k){
                freq[nums[left]]--;
                left++;
            }

            int current = right -left +1;
            res = max(res,current);
        }
        return res;
    }
};