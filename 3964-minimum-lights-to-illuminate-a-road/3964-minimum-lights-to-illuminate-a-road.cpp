class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int>maxDiff(n+1,0);
        // 1-> starting postion 
        // -1 -> ending postion

        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int v = lights[i];
                int left = max(0,i-v);
                int right = min(n-1,i+v);

                maxDiff[left] +=1; // started from there
                maxDiff[right+1] -=1; // end here you can do maxDiff[right]--;
            }
        }   
        int res = 0;
        vector<bool>visited(n,0);
        int currRun = 0;

        for(int i = 0;i<n;i++){
            currRun+= maxDiff[i];

            if(currRun>0){
                visited[i] = true;
            }
        }
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                res++;
                i+=2;
            }
        }
        return res;
    }
};



//Brute-Force
// O(n^2)
class Solution1 {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<bool>visited(n,false);

        for(int i = 0;i<n;i++){
            if(lights[i]>0){
                int v = lights[i];
                int left = max(0,i-v);
                int right = min(n-1,i+v);
                visited[i] = true;

                for(int j = left;j<=right;j++)
                    visited[j] = true;
            }
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){ 
                res++;
                i+=2;
            }
        }
        return res;
    }
};