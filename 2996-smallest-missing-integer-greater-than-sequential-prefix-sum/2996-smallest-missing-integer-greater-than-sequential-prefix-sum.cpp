class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int preSeq = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] == (nums[i - 1] + 1)) {
                preSeq += nums[i];
            } else
                break;
        }
        cout << "Prefix Sum: " << preSeq << endl;

        unordered_set<int> s;

        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        for (int x : s) {
            cout << x << endl;
        }

        while (s.count(preSeq)) {
            preSeq++;
        }
        return preSeq;
    }
};