class Solution {
public:
    const long long  mod = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int>res;
        int n = s.length();

        vector<long long>pow10(n+1,1);
        for(int i = 1;i<=n;i++){
            pow10[i] = (pow10[i-1]*10)%mod; 
        }


        vector<int>pSum(n+1,0);
        vector<int>cnt0(n+1,0);
        vector<long long>p(n+1,0);
        
        for(int i = 0;i<n;i++){
            int digit = s[i]-'0';

            pSum[i+1] = pSum[i]+digit;

            cnt0[i+1] = cnt0[i] + (digit>0?1:0);

            if(digit>0){
                p[i+1] = (p[i]*10+digit)%mod;
            } 
            else{
                p[i+1] = p[i];
            }
        }


        for(auto &i:queries){
            int r = i[1];
            int l = i[0];
            //number if 0's
            int n0 = cnt0[r+1]-cnt0[l]; 
            // sum
            long long  sum = pSum[r+1]-pSum[l];
            //product
            long long removePrefix = (p[l]*pow10[n0])%mod;
            long long x = (p[r+1] - removePrefix + mod)%mod;

            res.push_back((x*sum)%mod);
        }
        return res;
    }
};