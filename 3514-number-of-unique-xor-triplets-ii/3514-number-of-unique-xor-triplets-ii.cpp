class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        int maxEle = 0; // max element till we can go 

        for(int &x:nums){
            maxEle = max(maxEle,x);
        }

        int T = 1;

        while(T <= maxEle){
            T  = T << 1;
        }

        vector<bool>s1(T,false);
        vector<bool>s2(T,false);
        
        // MIXING ALL THE PAIRS i<= j
        for(int i = 0;i<n;i++){
            for(int j=i;j<n;j++){
                s1[nums[i] ^ nums[j]] = true;
            }
        }

        // Take the two pairs s1 we made then add the third one
        for(int i =0;i<T;i++){
            if(s1[i]==true){
                for(int num:nums){
                    s2[num ^ i] = true;
                }
            }
        }

        // count the uniqe pairs we made 

        int res = 0;
        for(int i = 0;i<T;i++){
            if(s2[i]==true){
                res++;
            }
        }
        return res;
    }
};