class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};
        vector<int>res(n);
        vector<pair<int,int>>test(n);
        for(int i = 0;i<n;i++){
            test[i].first = arr[i];  // value
            test[i].second = i;      // position
        }

        //sort accrding to value 

        sort(test.begin(),test.end());

        int rank = 1;
        res[test[0].second] = rank; 
        for(int i = 1;i<n;i++){
            if(test[i].first > test[i-1].first){
               rank++;
            }

            res[test[i].second] = rank;
        }
        return res;
    }
};