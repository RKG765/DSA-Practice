class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int greatest = 1;
        sort(arr.begin(),arr.end());  //nlogn

        arr[0]=1;   //first element always 1

        for(int i = 1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])>1){
                arr[i] = arr[i-1]+1;
            }
            greatest = max(greatest,arr[i]);
        }
        return greatest;
    }
};