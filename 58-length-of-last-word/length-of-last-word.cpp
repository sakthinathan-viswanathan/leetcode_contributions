class Solution {
public:
    int lengthOfLastWord(string s) {

        int l = 0;
        int r = s.length()-1;

        while(s[r] == ' '){
            r--;
        }

        int count = 0;

        for(int i=r;i>=0;i--){

            if(s[i] != ' '){
                count++;
            }
            else
            {
                return count;
            }
        }

    return count;
        
    }
};