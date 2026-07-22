void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]) {
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

int* constructST(int arr[], int n) {
    int* segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}

int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[]) {
    if (l > end || r < start) {
        return INT_MIN;
    }

    if (l >= start && r <= end) {
        return segmentTree[i];
    }

    int mid = l + (r - l) / 2;
    return max(querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree),
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}

int RMQ(int st[], int n, int a, int b) {
    return querySegmentTree(a, b, 0, 0, n - 1, st);
}

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int activeCount = count(begin(s), end(s), '1');

        vector<int> blockStart;
        vector<int> blockEnd;


        int i = 0;
        while(i < n) {
            if(s[i] == '0') {
                int start = i;
                while(i < n && s[i] == '0') i++;
                blockStart.push_back(start);
                blockEnd.push_back(i-1);
            } else {
                i++;
            }
        }  

        int m = blockStart.size();

        //If there is only one block of zeros
        //example : s = "11000011" , answer = simply count of 1s "activeCount"
        if(m < 2) {
            return vector<int>(queries.size(), activeCount);
        }

        vector<int> blockSize(m);
        for(int i = 0; i < m; i++) {
            blockSize[i] = blockEnd[i] - blockStart[i] + 1;
        }

        //Pairsum : blockSize[i] = blockSize[i] + blockSize[i+1]
        int N = blockSize.size()-1; //this many pairs will be there in pairSum
        //{2, 3, 4, 5, 2}
        vector<int> pairSum(N);
        for(int i = 0; i < N; i++) {
            pairSum[i] = blockSize[i] + blockSize[i+1];
        }

        int *st = constructST(pairSum.data(), N);

        vector<int> result;
        for(auto &q : queries) { //O(q*log)
            int l = q[0];
            int r = q[1];

            //first block in this range
            int low  = lower_bound(begin(blockEnd), end(blockEnd), l) - begin(blockEnd); //log
            int high = upper_bound(begin(blockStart), end(blockStart), r) - begin(blockStart) - 1; //log

            int maxPairSum = 0;
            if(low < high) { //we need atleast two blocks
                int firstLen = blockEnd[low] - max(blockStart[low], l) + 1; 
                int lastLen  = min(blockEnd[high], r) - blockStart[high] + 1;

                if(high - low == 1) { //exactly two blocks are there only
                    maxPairSum = firstLen + lastLen;
                } else {
                    int pair1 = firstLen + blockSize[low+1];
                    int pair2 = blockSize[high-1] + lastLen;
                    int RMQMaxPairSum = RMQ(st, N, low+1, high-2); //log
                    maxPairSum = max({pair1, pair2, RMQMaxPairSum});
                }
            }
            result.push_back(maxPairSum + activeCount);
        }

        return result;
    }
};



// Brute Force
//  TLE O(N x Q)
class Solution1 {
public:
    int solve(string& s, int total_ones) { // O(2n)-->time and O(n)-->space
        int currzeros = 0;
        vector<int> zero;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (currzeros > 0) {
                    zero.push_back(currzeros);
                    currzeros = 0;
                }
            } else
                currzeros++;
        }
        if (currzeros > 0)
            zero.push_back(currzeros);

        int maxZero = 0;
        for (int i = 1; i < zero.size(); i++) {
            maxZero = max(maxZero, zero[i - 1] + zero[i]);
        }
        return total_ones + maxZero;
    }
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {
        vector<int> res;
        int total_ones = count(s.begin(), s.end(), '1');
        for (auto& q : queries) {
            int len = q[1] - q[0] + 1;
            string temp = s.substr(q[0], len);
            res.push_back(solve(temp, total_ones));
        }
        return res;
    }
};