class Solution {
public:
    bool isPalin(string s){
        int l = 0;
        int r = s.length()-1;

        while(l<r){

            if(s[l] != s[r]){
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
    bool isPalindrome(string s) {

        string cur = "";

        int n = s.length();
        for(char c:s){
            if(isalnum(c)){
                    cur += tolower(c);
            }
        }

       return isPalin(cur);
    }
};