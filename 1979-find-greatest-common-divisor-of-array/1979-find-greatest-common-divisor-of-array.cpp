class Solution {
public:
    int findGCD(vector<int>& nums) {
      //potd --> atleast medium
      // range = 1<=ele<=1000  
      int maxEle = 0;
      int minEle = 1001;  

      for(int &i:nums){
            maxEle = max(maxEle,i);
            minEle = min(minEle,i);
      }
      return gcd(minEle,maxEle);
    }
};