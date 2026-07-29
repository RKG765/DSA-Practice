#include <algorithm> // reverse,next_permutation
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    // Math helper: Calculates distinct permutations of the remaining characters
    long long countPermutations(vector<int>& freq, long long kCap) {
        long long ways = 1;
        int currentLen = 0;

        for (int c = 0; c < 26; c++) {
            for (int i = 1; i <= freq[c]; i++) {
                currentLen++;
                ways = (ways * currentLen) / i;

                // Cap the ways so we don't cause an Integer Overflow
                if (ways > kCap) {
                    ways = kCap + 1;
                }
            }
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        int halfLen = n / 2;

        // 1. Grab the first half using your substring logic
        string temp = s.substr(0, halfLen);

        // 2. Count the frequencies of letters in the left half
        vector<int> freq(26, 0);
        for (char c : temp) {
            freq[c - 'a']++;
        }

        long long currentK = k;

        // Check if k is larger than all possible permutations
        if (countPermutations(freq, currentK) < currentK) {
            return "";
        }

        string leftHalf = "";

        // 3. Build the k-th permutation letter by letter (Left to Right)
        for (int i = 0; i < halfLen; i++) {
            // Try every possible character from 'a' to 'z'
            for (int c = 0; c < 26; c++) {
                if (freq[c] == 0)
                    continue; // No more of this letter left

                // Temporarily place this letter
                freq[c]--;

                // Calculate how many words we can make with the rest
                long long ways = countPermutations(freq, currentK);

                if (ways >= currentK) {
                    // Our answer is inside this block! Keep the letter.
                    leftHalf += (char)(c + 'a');
                    break;
                } else {
                    // Our answer is NOT here. Skip this entire block of words!
                    currentK -= ways;
                    freq[c]++; // Take the letter back and try the next one
                }
            }
        }

        // 4. Build the final string
        string res = leftHalf;

        // Add middle character if odd
        if (n % 2 != 0) {
            res += s[halfLen];
        }

        // Mirror and attach
        string rev = leftHalf;
        reverse(rev.begin(), rev.end());
        res += rev;

        return res;
    }
};

// TLE :
class Solution1 {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();

        // 1. get the first half of the string
        string temp = s.substr(0, n / 2);

        // 2. sort to get the smalles lexico possbile sol k -= 1
        sort(temp.begin(), temp.end());

        // 3. find the kth permutation as sorting it gives one permutaion
        for (int i = 1; i < k; i++) { // k * Q
            if (!next_permutation(temp.begin(), temp.end())) {
                return "";
            }
        }

        // building the final string
        string res = temp;

        // 4. check weather n is odd
        if (n % 2 != 0) {
            res += s[n / 2];
        }

        // 5. reverse the temp then attach it to the res
        reverse(temp.begin(), temp.end());

        res += temp;
        return res;
    }
};