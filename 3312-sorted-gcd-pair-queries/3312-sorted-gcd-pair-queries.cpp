class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // maxgcd = maxEle in nums
        int maxEle = 0;
        int n = nums.size();
        for(int i:nums){  // 0n
            maxEle = max(maxEle,i);
        }
        // jyda se jyda gcd maxEle tak hi ho sakta h
        vector<int>divisor(maxEle+1,0); 

        for(int i = 0;i<n;i++){ // 0n*max(len(num))
            int num = nums[i];

            // finding the factors
            for(int j = 1;j*j<=num;j++){
                if(num % j==0){
                    divisor[j]++;
                    if(num/j != j){
                        divisor[num/j]++;
                    }

                }
            }
        }
        // finding count 
        vector<long long>numOfPairs(maxEle+1,0);

        for(int factor = maxEle;factor>=1;factor--){ //maxEle^2
            // n-c-2 = n*(n-1)/2
            long long cnt = divisor[factor];
            numOfPairs[factor] = cnt * (cnt-1)/2;
            
            // also will remove the repeating values

            for(int mul = 2*factor;mul<=maxEle;mul+=factor){
                numOfPairs[factor]-=numOfPairs[mul];
            }
        }
        vector<long long>prefixCountGcd(maxEle+1,0);

        for(int i = 1;i<=maxEle;i++){
            prefixCountGcd[i] = prefixCountGcd[i-1]+numOfPairs[i];
        }

        vector<int>res;

        for(auto &idx:queries){
            int left = 1;
            int right = maxEle;
            int temp;

            while(left <= right){
                int mid = left + (right-left)/2;

                if(prefixCountGcd[mid]>idx){
                    temp = mid;
                    right = mid-1;
                }
                else{
                    left = mid +1;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};


class Solution1 {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        // find all the possible pairs then gcd it in new temp

        vector<int>pairGcd;
        int n = nums.size();
        for(int i = 0;i<n;i++){ // n^2logn
            for(int j = i+1;j<n;j++){
                pairGcd.push_back(gcd(nums[i],nums[j])); //gcd logn
            }
        }
        int m = pairGcd.size(); 
        sort(begin(pairGcd),end(pairGcd)); //mlogm
        nums.clear();
        nums.resize(queries.size());
        for(int i = 0;i<queries.size();i++){
            nums[i] = pairGcd[queries[i]];
        }
        return nums;
    }
};