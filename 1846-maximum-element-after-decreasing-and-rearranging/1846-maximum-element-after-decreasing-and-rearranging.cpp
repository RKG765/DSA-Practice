class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int greatest = 1;
        sort(arr.begin(),arr.end());  //nlogn
        for(int i = 0;i<arr.size();i++){
            if(i==0) arr[i]=1;
            else{
                if(abs(arr[i]-arr[i-1])>1){
                    arr[i] = arr[i-1]+1;
                }
                greatest = max(greatest,arr[i]);
            }
        }
        return greatest;
    }
};