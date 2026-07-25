class Solution {
public:
    // int max_int = 1e9+2;
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        // int res = max_int;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                // res = min(res,nums1[i]);
                // i++;
                // j++;
                return nums1[i];
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        // if(res==max_int) return -1;
        // return res;
        return -1;
    }
};