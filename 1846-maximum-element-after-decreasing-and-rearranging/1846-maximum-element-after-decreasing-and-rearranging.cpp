class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int greatest = 1;
        sort(arr.begin(),arr.end());  //nlogn

        if(arr[0]>1) arr[0]=1;   //first element always 1

        for(int i = 1;i<arr.size();i++){
            int num;
            if(abs(arr[i]-arr[i-1])>1){
                num = abs(arr[i]-arr[i-1]);
                arr[i] = abs(arr[i]-num) +1;
            }
            greatest = max(greatest,arr[i]);
        }
        return greatest;
    }
};