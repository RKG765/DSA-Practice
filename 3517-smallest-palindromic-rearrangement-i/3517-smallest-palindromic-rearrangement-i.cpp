#include<algorithm>  // for sort,reverse function

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if(n==1){
            return s;
        }
        string temp = "";
        string rev = ""; // for the reverse of the string 
        if(n%2==0){//even case
            temp = s.substr(0,n/2);
            sort(temp.begin(),temp.end());
            rev = temp;
            reverse(rev.begin(),rev.end());
            temp+=rev;
        }
        else{//odd case
            temp = s.substr(0,(n/2));
            sort(temp.begin(),temp.end());
            rev = temp;
            int left_idx = (n/2); // 5/2=  2 but we need 3 one aswell 
            temp += s[left_idx];
            reverse(rev.begin(),rev.end());
            temp+= rev;
        }
        return temp;
    }
};