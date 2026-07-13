//Bruteforce apporach
// class Solution {
// public:
//     bool seqDig(int n){
//         int lastDig = n%10;
//         n/=10;

//         while(n){
//             int digit = n%10;
//             if(digit>=lastDig) return false;
//             if(digit!=lastDig-1) return false;
//             lastDig = digit;
//             n/=10;
//         }
//         return true;
//     }
//     vector<int> sequentialDigits(int low, int high) {
//        vector<int>res;

//        for(int i=low;i<=high;i++){
//             if(seqDig(i)){
//                 res.push_back(i);
//             }
//        } 
//        return res;
//     }
// };


// -------> Optimal
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>res;
        string str = "123456789";   // high upto 10^9 so max

        int low_len = to_string(low).length();
        int high_len = to_string(high).length();

        for(int len = low_len;len<=high_len;len++){

            for(int i = 0;i<=9-len;i++){
                string sequenceDigit = str.substr(i,len);
                int num = stoi(sequenceDigit);

                //now check the num is >=low and <=high
                if(num>=low && num<=high){
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};