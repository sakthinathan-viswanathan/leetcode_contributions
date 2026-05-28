class Solution {
public:
    int isPalindrome(int l,int r,string s){
        int n = s.length();

        int count = 0;

        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
            count++;
        }

        return count++;
    }
    int countSubstrings(string s) {

        int n = s.length();

        int count = 0;
        int max_count = 0;

        for(int i=0;i<n;i++){
            count += isPalindrome(i,i,s);
            count += isPalindrome(i,i+1,s);

            max_count = max(max_count,count);
        }
        
        return max_count;
    }
};