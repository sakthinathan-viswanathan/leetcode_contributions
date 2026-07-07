class Solution {
public:
    string checkpalindrome(string s,int l,int r){

        int n = s.size();

        while(l >= 0 && r < n ){
            if(s[l] != s[r]){
                break;
            }

            l--;
            r++;
        }

        return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {

        int n = s.size();

        string res = "";

        if(s.size() <= 1){
            return s;
        }

        for(int i=0;i<n-1;i++){

            string odd = checkpalindrome(s,i,i);

            string even = checkpalindrome(s,i,i+1);

            if(res.size() < odd.size()){
                res = odd;
            }

            if(res.size() < even.size()){
                res = even;
            }

        }


        return res;
        
    }
};