class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) return false;

        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;


        for(int i=0;i<s.length();i++){

            char char1 = s[i];
            char char2 = t[i];

            if(mp1.count(char1)){

                if(char2 != mp1[char1]){
                    return false;
                }
                
            }
            else
            {
                mp1[char1] = char2;
            }
            if(mp2.count(char2)){
                if(char1 != mp2[char2]){
                    return false;
                }
            }
            else
            {
                mp2[char2] = char1;
            }
        }

        return true;
    }
};