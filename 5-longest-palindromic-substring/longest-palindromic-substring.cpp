class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();

        if(s.length() == 0 || s == ""){
            return "";
        }
        
        string ans = "";

        for(int i=0;i<n;i++){
            
            string even = isPalindrome(i,i,s);
            string odd = isPalindrome(i,i+1,s);

            if(ans.size() < even.size()){
                ans = even;
            }

            if(ans.size() < odd.size()){
                ans = odd;
            }

        }

        return ans;
    }

    string isPalindrome(int l,int r,string s){

        

        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }

        return s.substr(l+1,r-l-1);
    }
};