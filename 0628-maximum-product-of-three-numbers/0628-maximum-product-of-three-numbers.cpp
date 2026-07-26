class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1005;
        int max2 = -1005;
        int max3 = -1005;

        int min1 = 1005;
        int min2 = 1005;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > max3) {
                if (nums[i] > max2) {
                    if (nums[i] > max1) {
                        max3 = max2;
                        max2 = max1;
                        max1 = nums[i];
                    } else {
                        max3 = max2;
                        max2 = nums[i];
                    }
                } else {
                    max3 = nums[i];
                }
            }
            // least element
            if (nums[i] < min2) {
                if (nums[i] < min1) {
                    min2 = min1;
                    min1 = nums[i];
                } else {
                    min2 = nums[i];
                }
            }
        }
        // now we have all the maximum of 3 three numbers and also two minimu
        // numbrs
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};