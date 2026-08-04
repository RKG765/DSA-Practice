class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int range = nums[nums.size()-1];
        int begin = nums[0];
        vector<int>res;

        for(;begin<=range;begin++){
            res.push_back(begin);
        }

        int x = 0;
        int y = 0;

        while(x<res.size() && y<nums.size()){
            if(nums[y]==res[x]){
                //res.erase(res.begin()+x);
                erase(res,res[x]);
                y++;
                //x++;
                continue;
            }
            x++;
        }
        return res;
    }
};