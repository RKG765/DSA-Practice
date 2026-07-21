class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int numOfOne = 0;
        int numOfZeros = 0;
        vector<int> zeros;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                numOfOne++;
                if (numOfZeros > 0) {
                    zeros.push_back(numOfZeros);
                    numOfZeros = 0;
                }
            } else
                numOfZeros++;
        }

        if (numOfZeros > 0) {
            zeros.push_back(numOfZeros);
        }

        // find the max zeros which you will convert to trade to maximum gain
        int maxGain = 0;
        for (int i = 1; i < zeros.size(); i++) {
            maxGain = max(maxGain, zeros[i - 1] + zeros[i]);
        }
        return maxGain + numOfOne;
    }
};
