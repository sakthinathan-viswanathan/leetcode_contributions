class Solution {
public:
    bool checkpalindrome(string s,int l,int r){

        while(l<r){
            if(s[l] != s[r]){
                cout<<"s[l] "<<s[l]<<" s[r] "<<s[r]<<endl;
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
    bool isPalindrome(string s) {

        int n = s.size();

        if(s.size() == 1){
            return true;
        }

        string pure = "";

        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                pure += tolower(s[i]);
            }
        }

        bool found = checkpalindrome(pure,0,pure.size()-1);



        
        return found;
    }
};