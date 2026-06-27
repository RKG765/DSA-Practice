class Solution {
public:
    typedef long long ll;
    int maximumLength(vector<int>& nums) {
        unordered_map<ll,int>map;
        int res = 0;
        for(int i:nums){
            map[i]++;
        }

        // case of 1's
        if(map[1]%2==0){
            res = map[1]-1;
        }
        else{
            res = map[1];
        }

        for(auto &[num, _]:map){
            if(num==1) continue;

            ll curr = num;
            int len = 0;

            while(map.count(curr) && map[curr]>1){
                len+=2;
                curr = curr * curr;
            }
            if(map.count(curr)==1){
                len+=1;
            }
            else len-=1;

            res = max(res,len);
        }
        return res;
    }
};