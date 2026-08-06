// first create the index of the digits in num
// for loop from left to right
// in that for loop add one more for loop digit=9 till s[i]-'0' to find weather
// the ith element which is bigger than idx[digit] if lies in the right side of
// the s[i]-'0' also as we know it is grater then swap these two and return it
// if no changes are needed then return the num

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        // as num range can be 0-9 create a size 10 array,vector
        // which will store the last apprearing elemenets last index
        int arr[10] = {-1};

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            arr[digit] = i;
        }

        // now will run a for loop to iterate throught the string s left->right
        for (int i = 0; i < n; i++) {
            // now will go from maxEle which is 9 to current element in string
            for (int digit = 9; digit > (s[i] - '0'); digit--) {
                // now if the digit larger than the current and also it apprears
                // after the s[i] ith index then we will have to swap
                //  return converted string
                if (arr[digit] > i) {
                    swap(s[i], s[arr[digit]]);
                    return stoi(s);
                }
            }
        }
        // if loops are finised then there is no change made so will return the
        // origin number
        return num;
    }
};

// If the last element is greater from the any inbetween num then it will fail
class Solution1 {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((s[i] - '0') < (s[j] - '0')) {
                    swap(s[i], s[j]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};