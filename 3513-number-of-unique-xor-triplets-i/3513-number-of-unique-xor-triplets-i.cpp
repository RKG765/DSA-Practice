class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int b = 0; // number of bits

        if(n<=2) return n;
        int temp = n;


        while(temp>0){
            b++;
            temp >>=1; // divide by 2
        }
        return 1<<b;
    }
};