class Solution {
public:

    int checkPalindrome(int l,int r,string s){

        int n = s.size();

        int count = 0;

        while(l >= 0 && r < n){
            if(s[l] != s[r]){
                break;
            }

            count++;
            l--;
            r++;
        }

        return count;
    }
    int countSubstrings(string s) {

        int n = s.size();

        int res = 0;

        for(int i=0;i<n;i++){

            res += checkPalindrome(i,i,s);
            res += checkPalindrome(i,i+1,s);
        }


        return res;
        
    }
};